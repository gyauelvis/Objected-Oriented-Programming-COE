#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Declaring global variables
bool isTrue = true;

// declaring the differiantor fxn
void differiantor();
void integrator();
void numberOfTerms();

// Global functions
bool verifyingUserInput(int value)
{
    bool return_value;
    (value == 1 || value == 2) ? return_value = true : return_value = false;
    return return_value;
}

int main()
{
    // 0 for background Color(Black)
    // A for text color(Green)

    // Outputting the project title
    cout << "\033[1;32m"
         << "PROJECT DX" << endl;

    // Declaring some local variable
    int userWants;

    // Asking the user for input
    while (isTrue)
    {
        // system("Color 07");
        cout << "\033[0m"
             << "1 - Ordinary Integration" << endl
             << "2 - Ordinary Differentiation" << endl;
        cin >> userWants;
        if (verifyingUserInput(userWants))
        {
            (verifyingUserInput(userWants) || userWants == 1) ? integrator() : differiantor();
        }
        else
        {
            // system("Color 04");
            cout << "\033[1;31m"
                 << "Not a specified input" << endl;
            continue;
        }
    }
}

// Function definition
void differiantor()
{
    string ans;
}
void integrator()
{
    string ans;
}

void numberOfTerms()
{
    int numTerms = 0;
    cout << "Number of terms in expression" << endl;
    cin >> numTerms;
    string expression[numTerms];
    for (int i = 0; i < numTerms; i++)
    {
        cout << i + 1 << " Term" << endl
             << "Quoefficient: ";
        cin >> expression[i];
    };
}