#include <iostream>
using namespace std;

// Definition of the base class
class rectangleType
{
private:
    double length;
    double width;

public:
    void setDimensions(double, double);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;
    rectangleType();
    rectangleType(double, double);
};

void rectangleType::setDimensions(double l, double w)
{
    (l >= 0) ? length = l : length = 0;
    (w >= 0) ? width = w : width = 0;
}
double rectangleType::getLength() const
{
    return length;
}
double rectangleType::getWidth() const
{
    return width;
}
double rectangleType::area() const
{
    return length * width;
}
double rectangleType::perimeter() const
{
    return 2 * (width + length);
}
void rectangleType::print() const
{
    cout << "Length = " << length
         << "; Width = " << width;
}

rectangleType::rectangleType(double l, double w)
{
    setDimensions(l, w);
}
rectangleType::rectangleType() : length(0), width(0){};

// Definition of the derived class
class boxType : public rectangleType
{
private:
    double height;

public:
    void setDimensions(double, double, double);
    double getHeight() const;
    double area() const;
    double volume() const;
    void print() const;
    boxType();
    boxType(double, double, double);
};

// Function definition of member functions
void boxType ::setDimensions(double l, double w, double h)
{
    // Rememeber if a function of the derived class overwrites(redefines) a function of the base class then to have access to the base class function in that particular function of the derived class we need to use the <baseClassName>::functionCall(...parameters)

    rectangleType::setDimensions(l, w);
    (h >= 0) ? height = h : height = 0;
}
double boxType::getHeight() const
{
    return height;
}
double boxType::area() const
{
    return 2 * ((getLength() * getWidth()) + (height * getLength()) + (height * getWidth()));
}
double boxType::volume() const
{

    return height * rectangleType::area();
};

void boxType::print() const
{
    rectangleType::print();
    cout << height;
}
boxType::boxType()
{
    // We do not trigger the base constructor of the class RectangleType because the default constructor will trigger automatically if values is passed to the object on its declaration.
    height = 0;
}
boxType::boxType(double l, double w, double h) : rectangleType(l, w)
{
    // Remember the data members of the base class are under the member access specifier private meaning the derived class doesn't have direct acess to it and hence to be able to initialize the members we need to call the constructor of the base class and we do that with a colon infront of our function definition followed by a function call to constructor in the base class
    (h >= 0) ? height = h : h = 0;
}