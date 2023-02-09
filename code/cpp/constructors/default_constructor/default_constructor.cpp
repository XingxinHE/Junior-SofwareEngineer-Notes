// Person.h header file
class Person {};

int main()
{
    // client code  
    Person trump;        //👈default constructor和destructor  
    Person biden(trump); //👈copy constructor  
    biden = trump;       //👈copy assignment operator
}