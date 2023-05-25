// Recursion functions: functions that return themselves
#include <iostream>
using namespace std;

unsigned long factFxn(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factFxn(n - 1);
}
int main()
{
    unsigned int n;
    cout << "Number: ";
    cin >> n;
    long result = factFxn(n);
    cout << "Factorial of " << n << " is " << result;
    return 0;
}