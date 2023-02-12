#include <iostream>
using namespace std;

int main()
{
    char x[32];
    char *p = x;

    cout << sizeof(x) << endl; // 32 = 32 * sizeof(char)
    cout << sizeof(p) << endl; // maybe one of 2/4/8 depending on the hardware

    cout << alignof(x) << endl; //   1 = alignof(char)
    cout << alignof(p) << endl; //   2/4/8 = alignof(char *) depending on the hardware

    return 0;
}
