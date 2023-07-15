// Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 pesewas toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected. Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total  number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another function, called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called display() displays the two totals. Make appropriate member functions const. Include a program to test this class. This program should allow the user to push one key to count a paying car, and another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and total cash and then exit.

#include <iostream>
#include <string>
#include <conio.h> //So as to determine the ESC key pressed
using namespace std;

class tollBooth
{
private:
    unsigned int numberOfCars;
    double amoutCollected;

public:
    tollBooth()
    {
        numberOfCars = 0;
        amoutCollected = 0;
    };
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
        int userChoice;
        cout << "1. Count Paying Car" << endl
             << "2. Count Non Paying Car" << endl;
        userChoice = getch();
        // The conio header file allows us to use this getch() which gets the ascii value of the key being pressed and it passes it to the userChoice var
        if (userChoice == 1)
            ayeduase.payingCar();
        else if (userChoice == 2)
            ayeduase.nopayCar();
        else if (userChoice == 27)
        {
            ayeduase.display();
            break;
        }
    }

    return 0;
}