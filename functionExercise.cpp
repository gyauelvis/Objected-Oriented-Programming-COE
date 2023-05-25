// Raising a number n to a power p is the same as multiplying n by itself p
// times. Write a function called power() that takes a double value for n and an
// int value for p, and returns the result as a double value. Use a default
// argument of 2 for p, so that if this argument is omitted, the number n will be
// squared. Write a main() function that gets values from the user to test this
// function

#include <iostream>

using namespace std;

float exponentFxn(int n, int p)
{

    if (p == 0)
        return 1;
    else if (p == 1)
        return n;
    else if (p > 1)
        return n * exponentFxn(n, (p - 1));
    else
    {
        return (n * exponentFxn(n, (p + 1)));
    }
}

int main()
{
    long n, p;
    cout << "Number: ";
    cin >> n;
    cout << "Exponent: ";
    cin >> p;
    float result = exponentFxn(n, p);
    (p < 0) ? result = 1 / result : result;
    cout << n << " exponent " << p << " = " << result;
    return 0;
}