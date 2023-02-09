#include <iostream>
#include <string.h>

using namespace std;

// Person.h header file
class Person
{
public:
	Person(const std::string &name);  // constructor
};


int main()
{
    Person p{}   //ERROR❌. No default constructor has been generated.
    return 0;
}