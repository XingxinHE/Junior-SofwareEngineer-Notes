#include <iostream>
using namespace std;

class Widget
{
public:
    void doWork() & { cout << "&" << endl; }
    void doWork() && { cout << "&&" << endl; }
};
Widget makeWidget()
{
    return Widget{};
}
int main()
{
    Widget makeWidget();
    Widget w;
    w.doWork();
    makeWidget().doWork();
}