// main.cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    // constructor
    Person(const string &name, int age):m_name(name), m_age(age){}

    // destructor 显示实现
    ~Person() {cout << "Explicitly declare destructor..." << endl;}
private:
    string m_name;
    int    m_age;
};

int main()
{
    Person obama("Obama", 80);            
    Person other = std::move(obama);    //suppose to use move assignment operator

    return 0;
}