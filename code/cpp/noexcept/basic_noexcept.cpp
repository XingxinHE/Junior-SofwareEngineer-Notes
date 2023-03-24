#include <iostream>
#include <utility>
#include <vector>
 
void may_throw();
void no_throw() noexcept;
auto lmay_throw = []{};
auto lno_throw = []() noexcept {};

int main()
{
    std::cout << std::boolalpha
        << "Is may_throw() noexcept? " << noexcept(may_throw()) << '\n'
        << "Is no_throw() noexcept? " << noexcept(no_throw()) << '\n'
        << "Is lmay_throw() noexcept? " << noexcept(lmay_throw()) << '\n'
        << "Is lno_throw() noexcept? " << noexcept(lno_throw()) << '\n';

    return 0;
}