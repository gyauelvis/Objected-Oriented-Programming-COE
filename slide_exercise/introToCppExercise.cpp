// Assuming there are 7.481 gallons in a cubic foot, write a program that asks
// the user to enter a number of gallons, and then displays the equivalent in
// cubic feet.
// ▪ Write a program that allows the user to enter a floating-point number
// representing degrees Celsius, and then displays the corresponding degrees
// Fahrenheit.
// ▪ You can convert temperature from degrees Celsius to degrees Fahrenheit by
// multiplying by 9/5 and adding 32.

#include <iostream>
#include <iomanip> //for setw
using namespace std;

bool isTrue = true;

void gallonsToCubicFoot()
{
    float gallonsValue;
    float cubicFootValue;
    cout << "Gallons: ";
    cin >> gallonsValue;
    cubicFootValue = gallonsValue * 7.481;
    cout << gallonsValue << " gallons = " << cubicFootValue << " cubic foot" << endl
         << "\n";
};

void celciusToFahrenheit()
{
    float celciusValue;
    float fahrenheitValue;
    cout << "Celcius: ";
    cin >> celciusValue;
    fahrenheitValue = (celciusValue * (9 / 5)) + 32;
    cout << celciusValue << " degree celcius = " << fahrenheitValue << " degree fahrenheit" << endl
         << "\n";
};

void endConversion()
{
    int ans;
    cout << "Want to do another conversion?" << endl
         << "1-Yes" << endl
         << "2-No" << endl;
    cin >> ans;
    (ans == 1) ? isTrue : isTrue = false;
}

void conversionToUndertake()
{

    while (isTrue)
    {
        int conversionUserWant;
        cout << "Converter" << endl;
        cout << "What conversion do you wanna do?" << endl;
        cout << "1 - Gallons to Cubic foot" << endl
             << "2 - Degrees Celcius to degrees Fahrenheit" << endl;
        cin >> conversionUserWant;
        if (conversionUserWant == 1)
        {
            gallonsToCubicFoot();
            endConversion();
        }
        else if (conversionUserWant == 2)
        {
            celciusToFahrenheit();
            endConversion();
        }
    }
}

int main()
{
    conversionToUndertake();
    return 0;
}