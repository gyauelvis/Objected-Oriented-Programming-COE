// Linda’s gift store specializes in wrapping small packages. For simplicity, we assume that a package is in the shape of a box with a specific length, width, and height. We will write a program that uses the class boxType to store the dimensions of a package. The program will ask the user to input the dimensions of the package and the cost (per square foot) to wrap the package. The program will then output the cost of wrapping the package. (The program assumes that the minimum cost of wrapping a package is $1.00.)

#include <iostream>
#include <iomanip>
#include "rectangleType_boxType_header_file.h"
using namespace std;

int main()
{
    boxType linda;
    double l, w, h, cost;
    cout << fixed << showpoint << setprecision(2);
    cout << "Enter Dimensions of the box " << endl
         << "Lenght: ";
    cin >> l;
    cout << "Width: ";
    cin >> w;
    cout << "Height: ";
    cin >> h;
    linda.setDimensions(l, w, h);
    cout << "Enter the cost of cost of wrapping a package(per square foot): ";
    cin >> cost;
    (cost < 1.00) ? cost = 1 : cost;
    cout << "Cost of wrapping package: " << linda.area() * cost;
}