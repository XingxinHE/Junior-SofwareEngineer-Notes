#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class lambda32xzj
{
public:    
    int operator() (int x, int y) const
    {
        return x + y;
    }
};

int main()
{
    // using lambda expression
    auto add = [] (int x, int y) { return x + y;};
    int i = 13;
    cout << add(i, 3) << endl;
    cout << add.operator()(i, 3) << endl;
    
    // using function object
    auto addObject = lambda32xzj{};
    int j = 13;
    cout << addObject(j, 3) << endl;
    cout << addObject.operator()(j, 3) << endl;

    return 0;
}