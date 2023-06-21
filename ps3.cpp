// What are constructors?
// Constructors are member functions of a class with the same name as the class.
// They have no data type and they are immediately executed once the object is created

#include <iostream>
#include <string>
using namespace std;

// Formal parameters of a function
int clockType(int, int, float);
// Actual parameters;
int myClock(int sec, int min, int clock);

// Suppose that you have 100 employees who are paid on an hourly basis, and you need to keep track of their arrival and departure times. You can declare two arrays—arrivalTimeEmp and departureTimeEmp—of 100 components each, wherein each component is an object of type clockType

class EmployeeInfo
{
    // Private keyword not written since by default all members are private
    int hr, sec, min;

public:
    // Default constructor responsible for initializing the data members;
    EmployeeInfo() : hr(0), sec(0), min(0){};
    // Constructor with arguments specified by the user in declaration
    EmployeeInfo(int s, int m, int h);
    void setTime(int, int, int);
    void printTime(int, int, int);
};

int main()
{
    // Here it is practically imposible to declare 100 objects for arrival and 100 for departure
    // You can declare two arrays—arrivalTimeEmp and departureTimeEmp—of 100 components each, wherein each component is an object of type EmployeeInfo
    EmployeeInfo arrivalTimeEmp[100];
    EmployeeInfo departureTimeEmp[100];
    // For Each of the 200 hundred arrays it is impossible to write constructors for each of them and hence the need to include a default constructor;
    // But for small number of arrays
    EmployeeInfo smallArray[2] = {EmployeeInfo(1, 2, 3), EmployeeInfo(3, 23, 3)};
};
