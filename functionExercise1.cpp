// Write a function called zeroSmaller() that is passed two int arguments by
// reference and then sets the smaller of the two numbers to 0. Write a main()
// program to exercise this function

#include <iostream>

using namespace std;
float *zeroSmaller(float fNumb, float sNumb)
{
    (fNumb < sNumb) ? fNumb = 0 : sNumb = 0;
    static int arr[] = {fNumb,
                        sNumb};
    return arr;
}
int main()
{
    float fNumb, sNumb;
    cout << "Enter two numbers" << endl
         << "Number 1: ";
    cin >> fNumb;
    cout << "Number 2: ";
    cin >> sNumb;
    float result[] = zeroSmaller(fNumb, sNumb);
    cout << result[0], result[1] << endl;
    return 0;
}