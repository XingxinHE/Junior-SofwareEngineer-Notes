void func(int size)
{
    double dArr[3];              //✅IJ in stack (compile time)
    int*   pInt = new int[size]; //✅OK in heap
    delete[] pInt;
    int    iArr[size];           //❌No in stack (run time)
}
int main()
{
    func(10);
    return 0;
}