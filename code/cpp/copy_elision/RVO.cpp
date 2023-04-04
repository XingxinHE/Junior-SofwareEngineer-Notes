#include <cstdio>
struct Arg {};
struct S
{
    S() { puts("Default construct"); }
    S(Arg) { puts("Value construct"); }
    explicit S(int) { puts("Explicit value construct (1)"); }
    explicit S(int, int) { puts("Explicit value construct (2)");}
    ~S() { puts("Destruct"); }
    S(const S&) { puts("Copy construct"); }
    S(S&&) { puts("Move construct"); }
    S& operator=(const S&) { puts("Copy assign"); return *this; }
    S& operator=(S&&) { puts("Move assign"); return *this; }
};

// YES
const S will_it_rvo1()
{
    return S{1};
}

// YES
S will_it_rvo2(bool b)
{
    if (b)
        return S{1};
    else
        return S{0};
}

// NO
S will_it_rvo3(bool b, S s)
{
    if (b)
        s = S{1};
    return s;
}

// YES
S get_S() { return S{1}; }
S will_it_rvo4(bool b)
{
    if (b)
        return get_S();
    return S{0};
}

// YES(Clang)
// NO(GCC, MSVC)
S will_it_rvo5(bool b)
{
    if (b)
    {
        S s{1};
        return s;
    }
    return S{0};
}

// NO
S will_it_rvo6(bool b)
{
    S s{1};
    if (b)
        return s;
    return S{0};
}

// NO
S will_it_rvo7(bool b)
{
    S s{1};
    return b ? s : S{0};
}

// YES
S will_it_rvo8(bool b)
{
    return b ? get_S() : S{0};
}

// YES
S will_it_rvo9()
{
    S s{1};
    s = S{2};
    return s;
}

// YES(Clang)
// NO(GCC, MSVC)
S will_it_rvo10()
{
    S s{1};
    return (s);
}

void format()
{
    puts("\n ---------------------- \n");
}

int main()
{
    format();
    {
        auto s = will_it_rvo1();
    }
    format();
    {
        auto s = will_it_rvo2(true);
    }
    format();
    {
        auto s = will_it_rvo3(true, S());
    }
    format();
    {
        auto s = will_it_rvo4(true);
    }
    format();
    {
        auto s = will_it_rvo5(true);
    }
    format();
    {
        auto s = will_it_rvo6(true);
    }
    format();
    {
        auto s = will_it_rvo7(true);
    }
    format();
    {
        auto s = will_it_rvo8(true);
    }
    format();
    {
        auto s = will_it_rvo9();
    }
    format();
    {
        auto s = will_it_rvo10();
    }
    return 0;
}