// Write a function called zeroSmaller() that is passed two int arguments by
// reference and then sets the smaller of the two numbers to 0. Write a main()
// program to exercise this function

#include <iostream>

using namespace std;
void zeroSmaller(float *fNumb, float *sNumb)
{
    (*fNumb < *sNumb) ? *fNumb = 0 : *sNumb = 0;
}

int main()
{
    float fNumb, sNumb;
    cout << "Enter two numbers" << endl
         << "Number 1: ";
    cin >> fNumb;
    cout << "Number 2: ";
    cin >> sNumb;
    zeroSmaller(&fNumb, &sNumb);
    return 0;
}