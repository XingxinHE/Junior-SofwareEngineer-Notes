#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    auto twice = [] (const auto &item)
    {
        return item + item;
    };

    cout << twice(3) << endl;                       //✅
    cout << twice(1.2) << endl;                     //✅
    cout << twice(std::string{"Hello!"}) << endl;   //✅
    //cout << twice("Hello!") << endl;                //❌. since this is const char[7]
    
    return 0;
}