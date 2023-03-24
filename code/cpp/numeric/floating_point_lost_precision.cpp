#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float x = 1.0/333;
    float sum = 0;
    for(int ii = 0; ii<333; ++ii) sum += x;
    cout << setprecision(15) << sum << endl;

    return 0;
}