#include <iostream>
#include <string>
using namespace std;

// int sub(int a, int b)
// {
//     return a - b;
// };
// int add(int a, int b)
// {
//     return a + b;
// };

// int operation(int a, int b, int (*funtCall)(int, int))
// {
//     return funtCall(a, b);
// }

string revNum(long long n)
{
    string str = to_string(n);
    return str;
}

int main()
{
    cout << revNum(2);

    return 0;
}