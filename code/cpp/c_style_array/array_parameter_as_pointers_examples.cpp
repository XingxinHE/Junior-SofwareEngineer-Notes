#include <iostream>
using namespace std;

/*
 * Array parameter decays to pointer.
 * The followings demonstrate their usage are the same.
 */

int str_length1(const char* p) // similar to the standard library strlen()
{
    int count = 0;
    while (*p) { ++count; ++p; }
    return count;
}

int str_length2(const char* p) // similar to the standard library strlen()
{
    int count = 0;
    while (p[count]) { ++count;  }
    return count;
}

int str_length3(const char a[] ) // similar to the standard library strlen()
{
    int count = 0;
    while (a[count]) { ++count; }
    return count;
}

int str_length4(const char a[] ) // similar to the standard library strlen()
{
    int count = 0;
    while (*a) { ++count; ++a; }
    return count;
}

int main()
{
    const char* name = "Steve";
    cout << str_length1(name) << endl;
    cout << str_length2(name) << endl;
    cout << str_length3(name) << endl;
    cout << str_length4(name) << endl;

    return 0;
}