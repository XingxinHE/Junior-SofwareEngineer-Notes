#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

template<typename T>
void printFunc(const T &elems)
{
    for(const auto &elem : elems)
    {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void call(std::function<void(vector<T>)> func, const vector<T> &vec)
{
    func(vec);
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