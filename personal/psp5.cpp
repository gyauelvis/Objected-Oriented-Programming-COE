// Jim’s lawn care store specializes in putting up fences around small farms and home lawns and fertilizing the farms and lawns. For simplicity, we assume that the yards and farms are rectangular. In order to put up the fence, the program needs to know the perimeter, and to fertilize, the program needs to know the area. We will write a program that uses the class rectangle to store the dimensions of a yard or a farm. The program will also prompt the user to input the dimensions (in feet) of a yard or farm, the cost (per foot) to put up the fence, and the cost (per square foot) to fertilize the area. The program will then output the cost of putting up the fence and fertilizing the area.

#include <iostream>
#include <iomanip>
#include "rectangleType_boxType_header_file.h"

int main()
{
    // Declaring an object
    rectangleType farm;
    double l, w, fenceCost, fertilizerCost;
    cout << fixed << showpoint << setprecision(2);
    cout << "Enter Dimensions of Farm" << endl
         << "Lenght(feet): ";
    cin >> l;
    cout << "Width(feet): ";
    cin >> w;
    farm.setDimensions(l, w);
    cout << "Enter the cost of fence (per foot) in $: ";
    cin >> fenceCost;
    cout << "Enter the cost to fertilize an area (per square area) in $: ";
    cin >> fertilizerCost;
    cout << "The cost of putting up a fence for " << farm.getLength() << " length and " << farm.getWidth() << " width farm is $ " << farm.perimeter() * fenceCost << endl;
    cout << "The cost of fertilizing your " << farm.area() << " square feet farm is " << farm.area() * fertilizerCost << endl;
    cout << "Total Amout: " << (farm.perimeter() * fenceCost) + (farm.area() * fertilizerCost);
    fertilizerCost;
    return 0;
}