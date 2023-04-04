// PROGRAM 1
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
	t1.y = 20;
	cout << t1.y;
	return 0;
}
