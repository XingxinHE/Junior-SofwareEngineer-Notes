#include <iostream>
#include <algorithm>
using namespace std;

class vector
{
private:
	int m_size;
	double* m_elem;
public:
	vector(int s)
		:m_size{s}, m_elem{new double[s]} { cout << "default ctor!" << endl; }

	vector(const vector&) ; // 👈 declare copy constructor: define copy
	vector& operator=(const vector&) ;  // 👈here is `copy assignment operator`

	vector(vector&& ); // 👈move constructor
	vector& operator=(vector&&); // 👈move assignment

	~vector() { cout << "destructor!" << endl; delete[] m_elem; }
};

//move ctor
vector::vector(vector&& rhs)
	:m_size{rhs.m_size}, m_elem{rhs.m_elem} // copy a’s elem and sz
{
	rhs.m_size = 0; // make a the empty vector
	rhs.m_elem = nullptr;
	cout << "move ctor!" << endl;
}

//move assignment
vector& vector::operator=(vector&& rhs) // move `a` to this vector
{
	cout << "move assignment!" << endl;
	delete[] m_elem; // deallocate old space
	m_elem = rhs.m_elem; // copy a’s elem and sz
	m_size = rhs.m_size;
	rhs.m_elem = nullptr; // make a the empty vector
	rhs.m_size = 0;
	return *this; // return a self-reference (see §17.10)
}

// copy ctor
vector:: vector(const vector& rhs)
	:m_size{rhs.m_size}, m_elem{new double[rhs.m_size]}
{
	cout << "copy ctor!" << endl;
	std::copy(rhs.m_elem, rhs.m_elem + rhs.m_size, m_elem);
}

// copy assignment
vector& vector::operator=(const vector& rhs)
{
	cout << "copy assignment!" << endl;
	if (this == &rhs)  // 👈prevent self assignment
		return *this;
	double* p = new double[rhs.m_size];
	std::copy(rhs.m_elem, rhs.m_elem + rhs.m_size, p);
	delete[] m_elem;
	m_elem = p;
	m_size = rhs.m_size;
	return *this; // return a self-reference
}

vector createVector()
{
	vector res{3};
	cout << "create" << endl;
	return res;	
}

int main() // C++ programs start by executing the function main
{

	{
		cout << "experiment 1 ==================" << endl;
		vector vec = std::move(createVector());
	}


	{
		cout << "experiment 2 ==================" << endl;
		vector vec = createVector();
	}

	{
		cout << "experiment 3 ==================" << endl;
		vector vec{1};
		vec = createVector();
	}
    return 0;
}