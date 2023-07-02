// In this example, a function, isPalindrome, is designed that returns true if a string
// is a palindrome and false otherwise. A string is a palindrome if it reads forward and
// backward in the same way. For example, the strings "madamimadam", "5", "434",
// and "789656987" are all palindromes

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    int j = str.length() - 1, i = 0;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    cout << isPalindrome("civic1");
    return 0;
}