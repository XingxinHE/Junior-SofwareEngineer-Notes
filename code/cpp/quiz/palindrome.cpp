#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<int> vec;

bool is_palindrome(const string& str)
{
    if(str.empty())
        return true;
    int first = 0;
    int last = str.length() - 1;

    while(first < last)  //👈we haven’t reached the middle
    {
        if (str[first]!=str[last])
            return false;
        ++first;
        --last;
    }
    return true;
}

bool is_palindrome(const char s[] , int n)
{
    int first = 0;
    int last = n - 1;
    while (first < last) // 👈we haven’t reached the middle
    {
    if (s[first]!=s[last])
        return false;
    ++first; // move forward
    --last;  // move backward
    }
    return true;
}

bool is_palindrome(const char* first, const char* last)
{
    while (first < last)
    {
        if (*first != *last)
            return false;
        ++first; // move forward
        --last; // move backward
    }
    return true;
}

bool is_palindrome_recursive(const char* first, const char* last)
{
    if (first<last)
    {
        if (*first != *last)
            return false;
        return is_palindrome(first + 1, last - 1);
    }
    return true;
}

int main()
{
    string str_name = "malayalam";
    char ch_name[] = "malayalam";
    cout << is_palindrome(str_name) << endl;
    cout << is_palindrome(ch_name, 9) << endl;
    cout << is_palindrome(&ch_name[0], &ch_name[0] + 8) << endl;
    cout << is_palindrome_recursive(ch_name, ch_name + 8) << endl;

    return 0;
}