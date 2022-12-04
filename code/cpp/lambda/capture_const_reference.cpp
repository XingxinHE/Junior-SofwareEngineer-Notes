#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>
using namespace std;

int main()
{
    vector<string> strs{"ONE", "TWO", "THREE", "FOUR", "FIVE"};
    auto printElem = [&strs = std::as_const(strs)] (int input)
    {
        for(const auto &str : strs)
        {
            cout << str << " " << input << endl;
        }
    };

    printElem(1);
    printElem(2);
    printElem(3);
    return 0;
}
