#include <iostream>
#include <string>
using namespace std;

// Create a class called Quadrilateral.
class quadrilateral
{
    // It should have private integer variables x and y.
private:
    int x, y;

    // This class should have two functions: set_values will pass two integer values to
    // the variables x and y while area will calculate and return the product of the two
    // variables.
public:
    void set_values(int val1, int val2)
    {
        x = val1;
        y = val2;
    }
    int area()
    {
        return x * y;
    }
};

int main()
{
    // Create two objects from this class, square and rectangle.
    quadrilateral square, rectangle;
    // Using set_values, set the x and y variables for square to 10 and 10.
    square.set_values(10, 10);
    // Using set_values, set the x and y variables for rectangle to 5 and 10.
    rectangle.set_values(5, 10);
    // Using area, display the area values for square and rectangle on the console
    cout << "Area of Square: " << square.area() << endl
         << "Area of Rectangle: " << rectangle.area() << endl;
    return 0;
}