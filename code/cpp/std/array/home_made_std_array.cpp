#include <iostream>
template<typename T, int N>
struct array
{
    //👇C-style array is who actually holds something.
    T elem[N];

    /////////////////////////////////////////////////////////
    /* Rule of 0: compiler generated functions are here... */
    /////////////////////////////////////////////////////////
    
    //👇get & set by subscript overloading
    T& operator[] (int n) { return elem[n]; }
    const T& operator[] (int n) const { return elem[n]; }
	
    //👇have get & set the pointer which holds data elements.
    //  std::array is just a fancy wrapper of C-style array, right?
    T* data() { return elem; }
    const T* data() const { return elem; }
	
    int size() const { return N; }
};

int main()
{
    array<int, 256> gb = {1,2,3};
    array<double, 6> d = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
    
    std::cout << gb[2] << std::endl;
    double* pd = d.data();
    pd[3] = 100.0;
    std::cout << *pd << " " << pd[2] << " " << pd[3] << std::endl;

    return 0;
}