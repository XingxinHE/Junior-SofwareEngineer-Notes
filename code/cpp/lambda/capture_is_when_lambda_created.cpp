#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main()
{
    string prefix = "elem: ";

    auto printElem = [prefix] (int i) {
        cout << prefix << i << endl;
    } ;
    
    prefix = "value: ";
    printElem(13);
    return 0;
}