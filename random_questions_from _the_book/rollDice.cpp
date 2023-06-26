// the function rollDice rolls a pair of dice until the sum
// of the numbers rolled is a given number and returns the number of times the dice are
// rolled to get the desired sum. In fact, we can design a class that implements the basic
// properties of a die. Consider the definition of the following class die

#include <iostream>
#include <string>
#include <cstdlib> // The header file containing the rand() and srand;
#include <time.h>

using namespace std;

class dice
{
    int num;

public:
    dice()
    {
        num = 0;
        srand(time(0));
    };
    void roll();
    void getNum() const;
};

void dice::roll()
{

    num = rand() % 6 + 1;
};
void dice::getNum() const
{
    cout << "num: " << num << endl;
};

int main()
{
    dice d1;
    for (int i = 0; i < 50; i++)
    {
        d1.roll();
        d1.getNum();
    }

    return 0;
}