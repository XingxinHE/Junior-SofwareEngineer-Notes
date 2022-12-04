#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>
#include <iterator>
using namespace std;

int main()
{
    auto changed = [prev = 0] (auto val) mutable {
        bool changed = (prev != val);
        prev = val;
        return changed;
    };

    vector<int> numbers{7, 42, 42, 0, 3, 3, 7};
    copy_if(numbers.cbegin(), numbers.cend(), ostream_iterator<int>{cout, " "}, changed); cout << endl;
    copy_if(numbers.cbegin(), numbers.cend(), ostream_iterator<int>{cout, " "}, changed); cout << endl;
    copy_if(numbers.cbegin(), numbers.cend(), ostream_iterator<int>{cout, " "}, changed); cout << endl;
    changed(7);
    copy_if(numbers.cbegin(), numbers.cend(), ostream_iterator<int>{cout, " "}, changed); cout << endl;
    return 0;
}
