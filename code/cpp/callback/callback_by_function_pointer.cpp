#include <iostream>
#include <string>

using namespace std;

string startKUKA(int amount)
{
    return string{"Start " + std::to_string(amount) + " KUKA robots!"};
}

string startABB(int amount)
{
    return string{"Start " + std::to_string(amount) + " ABB robots!"};
}

//👇`startRobot` is a callback function
void startMachine(string(*startRobot)(int), int amount)
{
    cout << startRobot(amount) << endl;
}

int main()
{
    startMachine(&startKUKA, 6);  //👈take the address of the function by `&`
    startMachine(&startABB, 3);   //👈take the address of the function by `&`
    return 0;
}