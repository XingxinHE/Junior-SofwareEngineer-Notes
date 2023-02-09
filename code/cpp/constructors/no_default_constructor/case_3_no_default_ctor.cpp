// main.cpp
#include <iostream>
#include <string>
class Person
{
public:
    // constructor    
    Person(const std::string &name, int age)
        :m_name(name), m_age(age)
    {}

    // destructor  
    ~Person() 
    {
        std::cout << "Explicitly declare destructor..." << std::endl;
    }
private:    
    std::string m_name;    
    int    m_age;
};

int main()
{    
    std::string NAME_1 = "Trump";    
    std::string NAME_2 = "Biden";    
    Person trump(NAME_1, 76);    
    Person biden(trump);                 
    trump = biden;                      //copy constructor 
    Person obama("Obama", 80);          //copy assignment operator  
    Person other = std::move(obama);    //move assignment operator    
    return 0;
}