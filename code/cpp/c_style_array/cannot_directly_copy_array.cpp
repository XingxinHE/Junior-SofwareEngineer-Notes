int main()
{
    int x[100];
    int y[100];
    // . . .
    x = y;          // error
    int z[100] = y; // error

    return 0;
}