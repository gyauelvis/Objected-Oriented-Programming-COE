#include <iostream>
using namespace std;

class CPolygon
{
protected:
    int width, height;

public:
    void set_values(int a, int b)
    {
        width = a, height = b;
    }
};

// From this parent class, create two derived classes; CRectangle and CTriangle. Each should have an integer function area, which will be used to calculate the area of a rectangle and a triangle respectively.

class CRectangle : public CPolygon
{
public:
    int area()
    {
        return width * height;
    }
};
class CTriangle : public CPolygon
{
public:
    int area()
    {
        return 0.5 * width * height;
    }
};

int main()
{
    CRectangle rect;
    CTriangle triangle1;
    rect.set_values(10, 5);
    triangle1.set_values(10, 5);
    cout << rect.area();
}
