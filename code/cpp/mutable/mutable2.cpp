// PROGRAM 2
#include <iostream>
using std::cout;

class Test {
public:
int x;
mutable int y;
Test() { x = 4; y = 10; }
};
int main()
{
	const Test t1;
	t1.x = 8;
	cout << t1.x;
	return 0;
}
