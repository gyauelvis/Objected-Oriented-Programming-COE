// The equation of a line in standard form is ax + by = c, wherein both a and b cannot be zero, and a, b, and c are real numbers. If b != 0, then –a/b is the slope of the line. If a = 0, then it is a horizontal line, and if b = 0, then it is a vertical line. The slope of a vertical line is undefined. Two lines are parallel if they have the same slope or both are vertical lines. Two lines are perpendicular if either one of the lines is horizontal and the other is vertical or the product of their slopes is –1.
// Design  the class lineType to store a line. To store a line, you need to store the values of a (coefficient of x), b (coefficient of y), and c. Your class must contain the following operations:
// a. If a line is nonvertical, then determine its slope.
// b. Determine if two lines are equal. (Two lines ax1 + by1 = c1 and ax2 + b y c2 are equal if either a1 = a2, b1 = b2, c1 = c2 and a1 = ka2 , b1=kb2 , and c1=kc2 for some real number k.)
// c. Determine if two lines are parallel.
// d. Determine if two lines are perpendicular.
// e. If two lines are not parallel, then find the point of intersection.
// Add appropriate constructors to initialize variables of lineType. Also write a program to test your class

#include <iostream>
#include <cmath>
using namespace std;
class lineType
{
private:
    double a, b, c, slope, point_intersection_x, point_intersection_y;

public:
    lineType();
    void setCoefficients(double a_val, double b_val, double c_val);
    void slopeOfLine();
    bool isVertical();
    bool isHorizontal();
    bool isEqual(lineType line);
    bool isParallel(lineType line);
    bool isPerpendicular(lineType line);
    void pointOfIntersection(lineType line);
};

lineType::lineType() : a(0.0), b(0.0), c(0.0), slope(0.0), point_intersection_x(0.0), point_intersection_y(0.0){};
void lineType::setCoefficients(double a_val, double b_val, double c_val)
{
    a = a_val, b = b_val, c = c_val;
}
void lineType::slopeOfLine()
{
    (b != 0) ? slope = -(a / b) : slope = 0;
}
bool lineType::isVertical()
{
    return (a == 0);
}
bool lineType::isHorizontal()
{
    return (b == 0);
}
bool lineType::isEqual(lineType line)
{
    return (a == line.a && b == line.b && c == line.c);
}
bool lineType::isParallel(lineType line)
{
    return (slope == line.slope || (isVertical() && line.isVertical() || (isHorizontal() && line.isHorizontal())));
}
bool lineType::isPerpendicular(lineType line)
{
    bool returnVal;
    if ((isVertical() && line.isHorizontal()) || (isHorizontal() && line.isVertical()))
    {
        returnVal = true;
    }
    else if (!isVertical() && !isHorizontal())
    {
        (slope * line.slope == -1) ? returnVal = true : returnVal = false;
    }
    return returnVal;
}

void lineType::pointOfIntersection(lineType line)
{
    if (!isParallel(line))
    {
        point_intersection_x = (line.b * c - line.c * b) / (line.b * a - line.a * b);
        point_intersection_y = (c - a * (point_intersection_x)) / b;
    }
}

int main()
{
    lineType *line[2];
    float *a = new float;
    float *b = new float;
    float *c = new float;
    *line = new lineType[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Line " << i + 1 << ": " << endl;
        cout << "a = ";
        cin >> *a;
        cout << "b = ";
        cin >> *b;
        cout << "c = ";
        cin >> *c;
        line[i]->setCoefficients(*a, *b, *c);
    }
    cout << "line 1 Vertical:" << line[1]->isVertical();

    delete a;
    delete c;
    delete b;
    return 0;
}