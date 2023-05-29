// Create the equivalent of a four-function calculator.
// The program should ask the user to enter a number, an operator, and another number.
// It should then carry out the specified arithmetical operation: adding, subtracting, multiplying, or
// dividing the two numbers.
// Use a switch statement to select the operation.
// Finally, display the result.
// When it finishes the calculation, the program should ask whether the user wants to do another
// calculation. The response can be ‘y’ or ‘n’
#include <iostream>
// #include <iomanip>
// #include <string.h>
using namespace std;
bool isTrue = true;
void addition(float firstVal, float secVal)
{
    cout << firstVal << " + " << secVal << " = " << firstVal + secVal << endl;
}
void multiplication(float firstVal, float secVal)
{
    cout << firstVal << " * " << secVal << " = " << firstVal * secVal << endl;
}
void division(float firstVal, float secVal)
{
    cout << firstVal << " / " << secVal << " = " << firstVal / secVal << endl;
}
void subraction(float firstVal, float secVal)
{
    {
        cout << firstVal << " - " << secVal << " = " << firstVal - secVal << endl;
    }
}
void endCalc()
{
    char ans;
    cout << "Want to do another calculation ? "
         << " y or n" << endl;
    cin >> ans;
    switch (ans)
    {
    case 'y':
        isTrue;
        break;
    case 'n':
        isTrue = false;
        break;
    default:
        isTrue = false;
    }
}
int main()
{
    float firstValue, secondValue;
    int operatorTouse;
    while (isTrue)
    {
        cout << "CALCULATOR" << endl
             << "first value: ";
        cin >> firstValue;
        cout << "Operator: " << endl
             << "1 - Addition" << endl
             << "2 - Multiplication" << endl
             << "3 - Subtraction" << endl
             << "4 - Division" << endl;
        cin >> operatorTouse;
        cout << "second value: ";
        cin >> secondValue;
        if (operatorTouse == 1)
            addition(firstValue, secondValue);
        else if (operatorTouse == 2)
            multiplication(firstValue, secondValue);
        else if (operatorTouse == 3)
            subraction(firstValue, secondValue);
        else if (operatorTouse == 4)
            division(firstValue, secondValue);
    }
    return 0;
}