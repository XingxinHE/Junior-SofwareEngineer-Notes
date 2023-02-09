#include <iostream>
#include <string.h>

class Person
{
public:
    Person(int age, const std::string &name); // constructor

private:
    const int m_age;   // private data member (const)
    std::string &m_name; // private data member (reference)
};

Person::Person(int age, const std::string& name)
      :m_age{age}, m_name{name}
{
}

int main()
{
    std::string man_1("Trump");
    std::string man_2("Biden");
    Person trump{76, man_1};
    Person biden{79, man_2};
    trump = biden; //ERROR!!❌
    //  Here we need to use copy assignment operator but the compiler failed to generate for us.

    return 0;
}