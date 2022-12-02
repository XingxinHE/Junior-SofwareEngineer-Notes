#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class lambda32xzj
{

};

template<typename T>
void printFunc(const T &elems)
{
    for(const auto &elem : elems)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // lambda expression
    auto printLmbd = [] (const auto &elems)
    {
        for(const auto &elem : elems)
        {
            cout << elem << " ";
        }
        cout << endl;
    };
    
    vector<int> vecInt{1, 2, 3};
    vector<string> vecStr{"A", "B", "C"};

    printFunc(vecInt);
    printFunc(vecStr);

    printLmbd(vecInt);
    printLmbd(vecStr);
    
    return 0;
}