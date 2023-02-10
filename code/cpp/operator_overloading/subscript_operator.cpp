#include <iostream>
class vector
{
private:
    int m_size{0};
    double* mp_elem{nullptr};
public:
    // constructor
    vector(int size)
        :m_size{size}, mp_elem{new double[size]}
    {
        
    }
    // destructor
    ~vector()
    {
        delete[] mp_elem;
    }

    // operator[] overloading
    /* get */ double  operator[](int index) const { return mp_elem[index]; }
    /* set */ double& operator[](int index) { return mp_elem[index]; }
};

int main()
{
    vector v(10);
    double x = v[2];
    v[2] = 13;      // if we don't have "set" version, this will be error.
    for (size_t ii = 0; ii < 10; ++ii)
    {
        v[ii] = ii;
        std::cout << v[ii];
    }
    
    return 0;
}



