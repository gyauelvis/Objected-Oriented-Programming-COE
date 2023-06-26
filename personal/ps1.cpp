// Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 pesewas toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected.
// Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of these to 0.
// A member function called payingCar() increments the car total and adds 0.50 to the cash total.
// Another function, called nopayCar(), increments the car total but adds nothing to the cash total.
// Finally, a member function called display() displays the two totals. Make appropriate member functions const.
// Include a program to test this class. This program should allow the user to push one key to count a paying
// car, and another to count a nonpaying car. Pushing the Esc key should cause the program to print out the
// total cars and total cash and then exit

#include <iostream>
#include <conio.h>

using namespace std;

class Tollbooth
{
private:
    unsigned int countCars;
    double moneyCollected;

public:
    Tollbooth()
    {
        countCars = 0;
        moneyCollected = 0;
    }
    void payingCar()
    {

        countCars++;
        moneyCollected += 0.5;
    }
    void nopayCar()
    {

        countCars++;
        moneyCollected += 0;
    }
    void display() const
    {

        cout << "Total number of cars:" << countCars << endl;
        cout << "Total amount of money:" << moneyCollected << endl;
    }
};

int main()
{
    Tollbooth Augusco;
    char option;

    while (true)
    {
        cout << "Enter 1 for paying car:" << endl;
        cout << "Enter 2 for nopaying car:" << endl;
        option = getch();
        if (option == 1)
        {
            Augusco.payingCar();
        }
        else if (option == 2)
        {
            Augusco.nopayCar();
        }
        else if (option == 27)
        {
            Augusco.display();
            break;
        }
    }
    return 0;
}