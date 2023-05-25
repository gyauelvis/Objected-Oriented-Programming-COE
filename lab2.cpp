// 1. Build a body mass index calculator.
// 2. The program must ask for a person’s height in centimeters and weight in kilograms, one
// after the other. It should then display the BMI in kg/m2
// .
// 3. If the BMI is less that 18.5, the program also should respond with “You are
// underweight.”
// 4. If BMI falls in the range 18.5 and 24.9, the program should respond with “Your weight is
// normal.”
// 5. Between 25 and 29.9, it should respond with “You are overweight.”
// 6. Between 30 and 39.9, the expected response should be “You are obese.”
// 7. For a BMI of 40 and above, the program’s response should be “You are morbidly obese.”

#include <iostream>

using namespace std;

int main()
{
    float height, weight, bmi;
    cout << "Height(cm): ";
    cin >> height;
    cout << "Weight(kg): ";
    cin >> weight;
    bmi = (((height * (0.01))) * ((height * (0.01))));
    cout << "BMI(kg/m2) = " << bmi << endl;

    if (bmi < 18.5)
        cout << "You're underweight" << endl;
    else if (bmi >= 18.5 && bmi < 24.9)
        cout << "Your weight is normal" << endl;
    else if (bmi >= 24.9 && bmi < 29.9)
        cout << "You are overweight." << endl;
    else if (bmi >= 29.9 && bmi < 39.9)
        cout << "You are obese." << endl;
    else
        cout << "You are morbidly obese." << endl;
    return 0;
}