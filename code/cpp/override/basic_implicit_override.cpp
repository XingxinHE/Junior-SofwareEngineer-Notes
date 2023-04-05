#include <memory>

class Base {
public:
    virtual void doWork() {} // 👈base class virtual function
};

class Derived: public Base {
public:
    virtual void doWork() {} // 👈overrides Base::doWork
                             // ("virtual" is optional
};                           // here)

int main()
{
    // 👇 create base class pointer to derived class object;
    std::unique_ptr<Base> upb = std::make_unique<Derived>();

    upb->doWork(); // call doWork through base class ptr;
                   // derived class function is invoked

    return 0;
}