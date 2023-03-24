#include <iostream>
using namespace std;

class Animal {
public:
	void breath()
	{
		cout << "Breath... " << endl;
	}
};

class Mammal : public virtual Animal {
};

class Bird : public virtual Animal {
};

class Penguin : public Mammal, public Bird {
};

int main()
{
	Penguin pen;
	pen.breath();

    return 0;
}
