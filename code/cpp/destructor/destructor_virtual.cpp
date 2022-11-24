#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(){ cout << "base constructor" << endl; };
    virtual ~Shape() { cout << "base destructor" << endl; }
};

class Circle : public Shape
{
public:
    Circle(){ cout << "derived constructor" << endl; };
    ~Circle() override { cout << "derived destructor"<< endl; }
};

int main()
{
    Shape *pShape = new Circle{};
    delete pShape;
    return 0;
}