#include <iostream>
#include <ostream>

using namespace std;

class rectangleType{
    friend rectangleType operator+(const rectangleType&,const &rectangleType);
    friend ostream& operator<<(ostream&,const rectangleType&);

    private:
        double length, width;
    public:
        rectangleType(double l=0, double w=0);
        void setDimension(double l, double w);
        double getLength() const;
        double getWidth() const;
        double area() const;
        double perimeter() const;
        void print() const;
        rectangleType operator*(const rectangleType&);
        bool operator==(const rectangleType&);
        double operator!=(const rectangleType&);
};

void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
    length = l;
    else
    length = 0;
    if (w >= 0)
    width = w;
    else
    width = 0;
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
 return 2 * (length + width);
}
void rectangleType::print() const
{
 cout << "Length = " << length
 << "; Width = " << width;
}
rectangleType::rectangleType(double l, double w)
{
 setDimension(l, w);
};

rectangleType operator+(const rectangleType &a,const &rectangleType b){
    rectangleType tempObj;
    tempObj.length = b.length + a.length;
    tempObj.width = b.width + a.width;
    return tempObj;

}

rectangleType operator*(rectangleType &a){
    rectangleType tempObj;
    tempObj.length = length * a.length;
    tempObj.width = width * a.width;
    return tempObj;
}

bool rectangleType::operator==(const rectangleType &a){
    return (length==a.length&&width==a.width);
}
bool rectangleType::operator!=(const rectangleType &a){
    return (length!=a.length) || (width!=a.width);
}

// When an operator is overloaded in C++ in a class, the leftmost operand must be a that class
// cout<<myRectangle, the leftmost operand is cout which an object of the ostream 
// Hence when overloading, << and >> they function must not be a member of that class but a friend function.

ostream& operator <<(ostream& osObject,const rectangleType& myRect){
    osObject<<"Length: "<<myRect.length<<endl<<"Width: "<<myRect.width<<endl;
    return osObject
}