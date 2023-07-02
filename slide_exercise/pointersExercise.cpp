// Write a program that reads a group of numbers from the user and places them in an array of type float. Once the numbers are stored in the array, the program should average them and print the result. Use pointer notation wherever possible

#include <iostream>

using namespace std;

int main()
{
    int *numOfElements = new int;
    float *sum = new float;
    cout << "How many numbers: ";
    cin >> *numOfElements;
    float *array = new float[*numOfElements];
    for (int i = 0; i < *numOfElements; i++)
    {
        cout << "Number " << i + 1 << ": ";
        cin >> array[i];
        *sum += array[i];
    }
    cout << "Average: " << (*sum) / (*numOfElements);

    delete[] array;
    delete numOfElements;
    delete sum;
    return 0;
}