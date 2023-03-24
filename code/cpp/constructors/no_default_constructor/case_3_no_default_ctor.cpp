// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>

int main()
{    
    std::vector<int> numbers = {1,2,3};
    std::set<int> nums = {1,2,3,4,5};

    std::vector<int> vec{nums.cbegin(), nums.cend()};

    return 0;
}

