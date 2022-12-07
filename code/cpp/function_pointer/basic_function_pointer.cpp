#include <cstdlib>
#include <iostream>

using namespace std;
void Hello(int amount)
{
    cout << "Hello World! " << amount << endl;;
}
int main()
{
    void (*myProcess)(int); // declaration of the pointer
    myProcess = Hello;
    myProcess(3);
    myProcess = std::exit;
    myProcess(42); // calls std::exit
}