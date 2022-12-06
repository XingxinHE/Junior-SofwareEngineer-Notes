#include <iostream>


using namespace std;

class AbsoluteValue
{
public:
    double operator()(double input) const
    {
        return input < 0 ? -input : input;
    }
};


int main()
{
    AbsoluteValue absObject{};
    cout << absObject(-10.28);
    return 0;
}