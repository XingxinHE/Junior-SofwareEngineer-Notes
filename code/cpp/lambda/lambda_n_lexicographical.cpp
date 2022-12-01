#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    // function object to print
    auto print = [] (const std::vector<std::string> &str) -> void
    {   for(auto s : str)
        {
            std::cout << s << " "; std::cout << std::endl;
        }
    };
    // create a vector of string
    std::vector<std::string> coll{"Here", "are", "some", "cities", "Berlin", "LA",
                                  "London", "Cologne"};   

    // 1️⃣sort and print
    std::sort(coll.begin(), coll.end());
    print(coll);

    // 2️⃣sort and print lexicographical
    std::sort(coll.begin(), coll.end(),
              [] (const std::string& s1, const std::string& s2)
              {
                return std::lexicographical_compare(
                    s1.begin(), s1.end(),
                    s2.begin(), s2.end(),
                    [] (char c1, char c2) { return std::toupper(c1) < std::toupper(c2); });
              });
    print(coll);
    return 0;
}