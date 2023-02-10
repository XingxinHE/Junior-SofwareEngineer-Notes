// Person.h header file
class Person {};

int main()
{
    // client code  
    Person trump;        //👈generated default constructor and destructor  
    Person biden(trump); //👈generated copy constructor  
    biden = trump;       //👈generated copy assignment operator
}