#include <iostream>
using namespace std;

void yearBornCalculator()
{
    int currentYear = 2023;
    int age, yearBornIn;
    cout << "Enter your age" << endl;
    cin >> age;
    yearBornIn = currentYear - age;
    cout << "You were born in the year " << yearBornIn;
}

int main()
{
    // Declaring the variables and arrays int num1 = 17785;
    char pleasantry[] = "Welcome to this class!";
    long num1 = 17785;

    string greetings[1] = {"Guaaao"};

    cout << greetings;

    float num2 = -56.1427;
    char var[] = "5262778y";
    int num3 = 5, num4 = 5, num5 = 5;
    bool status = true;
    char lim10[10];

    // Initialize an integer array called “Marks” without a limit and with the following
    // values: 67, 71, 54, 43, 82, 90.
    int marks[] = {67, 71, 54, 43, 82, 90};

    // Change the third value to 75
    marks[2] = 75;

    // Pass the fifth value to a variable called “AppliedElectricity”
    int appliedElectricity = marks[4];

    // Printing out the declared variables
    cout << "Hello Word\n";
    cout << pleasantry << endl;
    cout << num2 + num1 << " is a negative number";

    yearBornCalculator();

    return 0;
}
