// 1. Write a global function to find the sum of the first n natural numbers.
// 2. Then prepare a program to accept an integer input that will call the function you wrote.
// 3. Write a function that receives the input of a person’s height in centimeters and returns
// the person’s height in feet.
// 4. Write a function to generate the Fibonacci sequence up to a given number

#include <iostream>

using namespace std;

int sum_of_first_n_numbers(int n);
float cmTofeet(float height);
void fibonacci_sequence(int n);

int main()
{
    int number;
    float height;

    cout << "Enter any natural number greater than 0" << endl
         << "n: ";
    cin >> number;
    cout << "The fibbonnaci sequence from the first to the " << number
         << " fibonnanci is ";
    fibonacci_sequence(number);
    cout
        << "The sum of the first " << number << " natural numbers is "
        << sum_of_first_n_numbers(number) << endl;
    cout << "Height in cm: ";
    cin >> height;
    cout << "Height in feet = " << cmTofeet(height) << endl;

    return 0;
}

int sum_of_first_n_numbers(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}

inline float cmTofeet(float height)
{
    return 0.0328084 * height;
};

void fibonacci_sequence(int n)
{
    int first_number = 0, second_number = 1, next_number;
    if (n == 1)
        cout << "[" << first_number << "]";
    else if (n == 2)
        cout << "[" << first_number << ", " << second_number << "]";
    else if (n > 2)
    {
        cout << "[" << first_number << ", " << second_number << " ,";
        for (int i = 3; i <= n; i++)
        {
            next_number = second_number + first_number;
            (i != n) ? cout << next_number << ", " : cout << next_number;
            // cout << next_number << ", ";
            first_number = second_number;
            second_number = next_number;
        }
        cout << "]" << endl;
    }
}
