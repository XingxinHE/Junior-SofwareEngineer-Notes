#include <iostream>

void foo (size_t n) 
{
    int x [n];  // ❌NO. dim must be constant. 
	int y [17]; // ✅ok. dim is constant. 
}

int main()
{
    foo(15);
}