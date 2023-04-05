#include <iostream>
using namespace std;

class Base
{
public:
    virtual void mf1() const { cout << "Base: mf1" << endl; }
    virtual void mf2(int x) { cout << "Base: mf2" << endl; }
    virtual void mf3() & { cout << "Base: mf3" << endl; }
    void mf4() const  { cout << "Base: mf4" << endl; }
};

class Derived: public Base
{
public:
    virtual void mf1() { cout << "Derived: mf1" << endl; }
    virtual void mf2(unsigned int x) { cout << "Derived: mf2" << endl; }
    virtual void mf3() && { cout << "Derived: mf3" << endl; }
    void mf4() const { cout << "Derived: mf4" << endl; }
};

int main()
{
    return 0;
}