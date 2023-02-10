#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X
{ // simple test class
    int val;
    void out(const string& s, int nv)
    { 
        cerr << this << "  ->  " << s << ": " << val << " (" << nv << ")\n";
    }
    
    // default constructor
    X()
    { 
        out("X()",0);
        val=0;
    }

    // other non-default constructor
    X(int v)
    { 
        val=v;
        out( "X(int)",v);
    }

    // copy constructor
    X(const X& x)
    { 
        val=x.val;
        out("X(const X&) ",x.val); 
    }

    // copy assignment
    X& operator=(const X& a)
    { 
        out("X::operator=()",a.val);
        val=a.val;
        return *this;
    }

    // destructor
    ~X()
    { 
        out("~X()",0);
    }
};

X glob(2); // a global variable

X copy(X a)
{ 
    return a; 
}

X copy2(X a)
{ 
    X aa = a;
    return aa; 
}

X& ref_to(X& a)
{ 
    return a;
}

X* make(int i)
{ 
    X a(i);
    return new X(a);
}

struct XX
{ 
    X a;
    X b;
};

// Take a guess of the following codes to
// verify you understand the concept of 
// special member functions.
int main()
{
    cout << "Experiment 1-------------------------" << endl;
    X loc {4}; // local variable
    X loc2 {loc}; // copy construction
    loc = X{5}; // copy assignment
    loc2 = copy(loc); // call by value and return
    loc2 = copy2(loc);

    cout << "Experiment 2-------------------------" << endl;
    X loc3 {6};
    X& r = ref_to(loc); // call by reference and return
    delete make(7);
    delete make(8);
    vector<X> v(4); // default values

    cout << "Experiment 3-------------------------" << endl;
    XX loc4;
    X* p = new X{9}; // an X on the free store
    delete p;
    X* pp = new X[5]; // an array of Xs on the free store
    delete[] pp;
}

//The results are:
// 0x7ff749dc8040  ->  X(int): 2 (2)
// Experiment 1-------------------------
// 0x2a7c5ffadc  ->  X(int): 4 (4)
// 0x2a7c5ffad8  ->  X(const X&) : 4 (4)
// 0x2a7c5ffae0  ->  X(int): 5 (5)
// 0x2a7c5ffadc  ->  X::operator=(): 4 (5)
// 0x2a7c5ffae0  ->  ~X(): 5 (0)
// 0x2a7c5ffae8  ->  X(const X&) : 5 (5)
// 0x2a7c5ffae4  ->  X(const X&) : 5 (5)
// 0x2a7c5ffad8  ->  X::operator=(): 4 (5)
// 0x2a7c5ffae4  ->  ~X(): 5 (0)
// 0x2a7c5ffae8  ->  ~X(): 5 (0)
// 0x2a7c5ffaf0  ->  X(const X&) : 5 (5)
// 0x2a7c5ffaec  ->  X(const X&) : 5 (5)
// 0x2a7c5ffad8  ->  X::operator=(): 5 (5)
// 0x2a7c5ffaec  ->  ~X(): 5 (0)
// 0x2a7c5ffaf0  ->  ~X(): 5 (0)
// Experiment 2-------------------------
// 0x2a7c5ffad4  ->  X(int): 6 (6)
// 0x2a7c5ffa5c  ->  X(int): 7 (7)
// 0x20fa8d92a50  ->  X(const X&) : 7 (7)
// 0x2a7c5ffa5c  ->  ~X(): 7 (0)
// 0x20fa8d92a50  ->  ~X(): 7 (0)
// 0x2a7c5ffa5c  ->  X(int): 8 (8)
// 0x20fa8d92a50  ->  X(const X&) : 8 (8)
// 0x2a7c5ffa5c  ->  ~X(): 8 (0)
// 0x20fa8d92a50  ->  ~X(): 8 (0)
// 0x20fa8d92a50  ->  X(): -1461034192 (0)
// 0x20fa8d92a54  ->  X(): 527 (0)
// 0x20fa8d92a58  ->  X(): -1461059248 (0)
// 0x20fa8d92a5c  ->  X(): 527 (0)
// Experiment 3-------------------------
// 0x2a7c5ffaa8  ->  X(): 2 (0)
// 0x2a7c5ffaac  ->  X(): 0 (0)
// 0x20fa8d92a70  ->  X(int): 9 (9)
// 0x20fa8d92a70  ->  ~X(): 9 (0)
// 0x20fa8d92a78  ->  X(): -1461059248 (0)
// 0x20fa8d92a7c  ->  X(): 527 (0)
// 0x20fa8d92a80  ->  X(): 0 (0)
// 0x20fa8d92a84  ->  X(): 0 (0)
// 0x20fa8d92a88  ->  X(): 1426063700 (0)
// 0x20fa8d92a88  ->  ~X(): 0 (0)
// 0x20fa8d92a84  ->  ~X(): 0 (0)
// 0x20fa8d92a80  ->  ~X(): 0 (0)
// 0x20fa8d92a7c  ->  ~X(): 0 (0)
// 0x20fa8d92a78  ->  ~X(): 0 (0)
// 0x2a7c5ffaac  ->  ~X(): 0 (0)
// 0x2a7c5ffaa8  ->  ~X(): 0 (0)
// 0x20fa8d92a50  ->  ~X(): 0 (0)
// 0x20fa8d92a54  ->  ~X(): 0 (0)
// 0x20fa8d92a58  ->  ~X(): 0 (0)
// 0x20fa8d92a5c  ->  ~X(): 0 (0)
// 0x2a7c5ffad4  ->  ~X(): 6 (0)
// 0x2a7c5ffad8  ->  ~X(): 5 (0)
// 0x2a7c5ffadc  ->  ~X(): 5 (0)
// 0x7ff749dc8040  ->  ~X(): 2 (0)