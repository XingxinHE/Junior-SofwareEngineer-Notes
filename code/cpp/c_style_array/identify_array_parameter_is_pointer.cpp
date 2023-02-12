#include <iostream>
using namespace std;

void foo(char x[])
{
    cout << sizeof(x) << endl; // 32 = 32 * sizeof(char)
    cout << alignof(x) << endl; //   1 = alignof(char)
}

int main()
{
    char ch[32];
    foo(ch);

    return 0;
}