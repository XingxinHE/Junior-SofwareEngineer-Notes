#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class lambda32xzj
{
private:
    int m_min{0};
    int m_max{0};
public:
    lambda32xzj(int min, int max)
        :m_min{min}, m_max{max}
        {}

    bool operator() (int num) const
    {
        return (m_min <= num) && (num <= m_max);
    }
};

int main()
{
    constexpr int MIN = 0;
    constexpr int MAX = 10;
    // using lambda expression
    auto inRange = [MIN, MAX] (int num)
    {
        return (MIN <= num) && (num <= MAX);
    };
    
    // using function object
    auto inRangeObject = lambda32xzj{MIN, MAX};

    // test in range
    vector<int> numbers{1, 32, 6};
    cout << "num in range: " << count_if(numbers.cbegin(), numbers.cend(), inRange) << endl;
    cout << "num in range: " << count_if(numbers.cbegin(), numbers.cend(), inRangeObject) << endl;

    return 0;
}