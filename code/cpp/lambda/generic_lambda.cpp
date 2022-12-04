#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class lambda32xzj
{
public:
    template<typename T1, typename T2>
    auto operator() (T1 x, T2 y) const
    {
        return x + y;
    }
};


int main()
{
    auto twice_Lambda = [] (const auto &item1, const auto &item2)
    {
        return item1 + item2;
    };

    // using lambda
    cout << twice_Lambda(3, 5) << endl;                       //✅
    cout << twice_Lambda(1.2, 5.6) << endl;                     //✅
    cout << twice_Lambda(string{"Hello "}, string{"World!"}) << endl;   //✅
    //cout << twice_Lambda("Hello ", "World!") << endl;                //❌. since this is const char[7]
    
    auto twice_FunctionObject = lambda32xzj{};
    cout << twice_FunctionObject(3, 5) << endl;                       //✅
    cout << twice_FunctionObject(1.2, 5.6) << endl;                     //✅
    cout << twice_FunctionObject(string{"Hello "}, string{"World!"}) << endl;   //✅
    //cout << twice_FunctionObject("Hello ", "World!") << endl;                //❌. since this is const char[7]


    return 0;
}