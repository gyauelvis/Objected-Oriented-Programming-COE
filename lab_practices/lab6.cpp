// PRACTICE
// 1. Write a function to find the largest number in a given integer array.
// 2. Write a function to find the smallest number in a given integer array.
// 3. Using pointers, write a single function to find both the largest and smallest numbers in a
// given integer array
#include <iostream>
using namespace std;

// Write a function that finds the largest number in a given arrray
int largestNumberFinder(int array[], int length)
{
    int largestNumber = array[0];
    for (int i = 0; i < length; i++)
    {
        if (largestNumber < array[i])
        {
            largestNumber = array[i];
        }
    }
    return largestNumber;
};

// 2. Write a function to find the smallest number in a given integer array.
int smallestNumberFinder(int array[], int size)
{
    int smallestNumber = array[0];
    for (int i = 0; i < size; i++)
    {
        if (smallestNumber > array[i])
        {
            smallestNumber = array[i];
        }
    }
    return smallestNumber;
}

// 3. Using pointers, write a single function to find both the largest and smallest numbers in a given integer array

void max_minFinder(int array[], int *length)
{

    int *largestNumber = &array[0];
    for (int i = 0; i < *length; i++)
    {
        if (*largestNumber < array[i])
        {
            *largestNumber = array[i];
        }
    }
    cout << "largestNumber" << *largestNumber << endl;

    int *smallest = &array[0];
    for (int i = 0; i < *length; i++)
    {
        if (*largestNumber > array[i])
        {
            *largestNumber = array[i];
        }
    }
    cout << "smallest: " << *smallest << endl;
}

int main()
{

    int array[] = {1, 56, 89, 34, 5, 89, 12, 90};
    int length = (sizeof(array) / sizeof(array[0]));
    cout << "Largest: " << largestNumberFinder(array, length) << endl
         << "Smallest: " << smallestNumberFinder(array, length) << endl;

    return 0;
}