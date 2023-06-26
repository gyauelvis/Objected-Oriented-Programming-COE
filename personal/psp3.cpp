#include <iostream>
using namespace std;

int sub(int a, int b)
{
    return a - b;
};
int add(int a, int b)
{
    return a + b;
};

int operation(int a, int b, int (*funtCall)(int, int))
{
    return funtCall(a, b);
}

int main()
{
    cout << operation(2, 3, sub);
}