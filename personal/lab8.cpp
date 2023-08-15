#include <iostream>
#include <string>

using namespace std;

class CPolygon {

protected:
int width, height;

public:
void set_values(int a , int b){

width = a, height = b;

};

// Add a public integer function area to the class which simply returns 0. Note that it should
// be defined in such a way that it can be altered by other derived classes.
virtual int area(){
    return 0;
};

};

// From this parent class, create two derived classes; CRectangle and CTriangle. Each
// should have its own integer function area, which will be used to calculate the area of a
// rectangle and a triangle respectively.

class CRectangle: public CPolygon{
    public:
    int area(){
        return width*height;
    }
};

class CTriangle:public CPolygon{
    public:
    int area(){
        return 0.5*width*height;
    }
};




int main(){

// 3. Initialize the following:
// a. An object rect of the CRectangle class.
CRectangle rect;

// b. An object trgl of the CTriangle class.
CTriangle trgl;

// c. An object poly of the CPolygon class.
CPolygon poly;

// d. A pointer ppoly1 for the object rect.
CPolygon *p1 = &rect;

// e. A pointer ppoly2 for the object trgl.
CPolygon *p2 = &trgl;

// A pointer ppoly3 for the object poly.
CPolygon *p3 = &poly;


// Using only the pointers ppoly1, ppoly2 and ppoly3;
// a. Set the width and height of the objects rect, trgl and poly to 10 and 5 respectively.
p1->set_values(10,5);
p2->set_values(10,5);
p3->set_values(10,5);
// b. Print out the areas of the three objects.
p1->area();
p2->area();
p3->area();

    return 0;
}

