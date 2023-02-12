#include <algorithm>
#include <cstring>
int main()
{
    constexpr int SIZE = 10;
    int x[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int y[100];

    // 1️⃣pointer using for loop
    for (size_t ii = 0; ii < SIZE; ++ii)
    {
        y[ii] = x[ii];
    }

    // 2️⃣memcpy
    memcpy(x, y, SIZE*sizeof(int));
    
    // 3️⃣std::copy
    std::copy(y, y+SIZE, x);

    
    return 0;
}