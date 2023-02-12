#include <iostream>
using namespace std;
/********LIFO_Stack.h********/
class LIFO_Stack
{
private:
        // ...
public:
        virtual ostream& print(ostream &os = cout) const;
        // ...
};



/********LIFO_Stack.cpp********/

// ❌following is WRONG, no need to specify the default value again in .cpp
ostream& LIFO_Stack::print(ostream &os = cout) const
{
        return os;
}

// ✅following is CORRECT
ostream& LIFO_Stack::print(ostream &os) const
{
        return os;
}

int main()
{
    return 0;
}