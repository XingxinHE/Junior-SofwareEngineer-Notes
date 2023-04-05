#include <iostream>
using namespace std;

class Base
{
public:
    virtual void mf1() const;
    virtual void mf2(int x);
    virtual void mf3() &;
    void mf4() const;
};

class Derived: public Base
{
public:
    virtual void mf1() override;
    virtual void mf2(unsigned int x) override;
    virtual void mf3() && override;
    void mf4() const override;
};

int main()
{
    return 0;
}