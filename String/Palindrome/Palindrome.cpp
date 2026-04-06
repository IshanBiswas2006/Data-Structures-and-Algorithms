#include <iostream>
#include <cctype>
using namespace std;

bool Palindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{

    string str;
    cout << "Enter word: ";
    getline(cin, str);

    if (Palindrome(str))
    {
        cout << "This word is Palindrome: " << str << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}