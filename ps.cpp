#include <iostream>
#include <string>    //So that we can use the string data type;
#include <windows.h> // We want to change colors the output
using namespace std;

int main()
{
    system("Color 2D"); // After the Color keyword the first value represents the color of the background we want and the second value the color of text. 
    int a, b;
    // static_cast<dataType>(expression) is used for explicit conversion of one data type of an expression to another.
    cout << static_cast<int>(2.345) << endl; // Outputs 2
    // Using the cin keyword to take in multiple values
    cin >> a >> b;
    cout << a << " " << b;
    // Post increment and Pre-increment
    int x = 5;   // Assigning 5 to x
    int y = ++x; // Assigning x = x + 1 to y. So here x will now be 6 and y = 6

    x = 5;
    y = x++; // Here y = x and afterwards x = x+ 1 is applied. so y holds 5, and x will now be 6;

    return 0;
}