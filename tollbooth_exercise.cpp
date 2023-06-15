#include <iostream>
#include <string>
#include <conio.h> //So as to determine the ESC key pressed
using namespace std;

class tollBooth
{
private:
    int numberOfCars;
    double amoutCollected;

public:
    tollBooth() : numberOfCars(0), amoutCollected(0){};
    void payingCar()
    {
        numberOfCars++;
        amoutCollected += 0.5;
    }
    void nopayCar()
    {
        numberOfCars++;
    }
    void display() const
    {
        cout << "Total Number of Cars: " << numberOfCars << endl
             << "Total Number of Money: " << amoutCollected << endl;
    }
};
int main()
{
    tollBooth ayeduase;

    while (true)
    {
        char userChoice;
        int asciiValue;
        cout << "1. Count Paying Car" << endl
             << "2. Count Non Paying Car" << endl;
        userChoice = getch();
        // The conio header file allows us to use this getch() which gets the ascii value of the key being pressed and it passes it to the userChoice var
        asciiValue = userChoice;
        if (userChoice == '1')
            ayeduase.payingCar();
        else if (userChoice == '2')
            ayeduase.nopayCar();
        else if (asciiValue == 27)
        {
            ayeduase.display();
            break;
        }
    }

    return 0;
}