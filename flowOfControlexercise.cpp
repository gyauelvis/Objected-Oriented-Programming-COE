// Write a temperature-conversion program that gives the user the option of converting
// Fahrenheit to Celsius or Celsius to Fahrenheit. Then carry out the conversion.
#include <iostream>
using namespace std;
bool isTrue = true;
float celciusValue, fahrenheitValue;
void celciusToFahrenheit()
{
    cout << "Degree Celcius: "; cin >> celciusValue;
    fahrenheitValue = (celciusValue * (9 / 5)) + 32;
    cout << celciusValue << " degree celcius = " << fahrenheitValue << " degree fahrenheit" << endl
         << "\n";
}

void fahrenheitToCelcius()
{
    cout << "Degree Fahrenheit: "; cin >> fahrenheitValue;
    celciusValue = (fahrenheitValue - 32) / (9 / 5);
    cout << fahrenheitValue << " degree fahrenheit = " << celciusValue << " degree celcius" << endl
         << "\n";
}
void endConversion()
{
    int ans;
    cout << "Want to do another conversion?" << endl
         << "1-Yes" << endl << "2-No" << endl;
    cin >> ans;
    (ans == 1) ? isTrue : isTrue = false;
}
void conversionToUndertake()
{
    while (isTrue)
    {
        int conversionUserWant;
        cout << "Converter" << endl;
        cout << "What conversion do you wanna do?" << endl
             << "1 - Degrees Fahrenheit to Degrees Celcius" << endl
             << "2 - Degrees Celcius to degrees Fahrenheit" << endl;
        cin >> conversionUserWant;
        if (conversionUserWant == 1)
        {
            fahrenheitToCelcius();
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