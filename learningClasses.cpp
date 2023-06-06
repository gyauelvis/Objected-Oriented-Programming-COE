#include <iostream>
using namespace std;

// Clock type class
class ClockType
{
    // private members
private:
    int hour, seconds, minutes;

    // Public Members
public:
    // const at the end of getTime(),printTime() and equalTime() indicates the functions can't modify the member variables of a variable type ClockType
    void setTime(int hr, int min, int sec);
    void getTime(int &, int &, int &) const;
    void printTime() const;
    void inc_sec();
    void inc_min();
    void inc_hour();

    // The parameter here is given the CONST data type so that the actual address of the parameter is passed as the function but the equalTime function cannot modify the value of the parameter.
    // We could have passed it as an actual value which would require the copying of the whole parameter which would result in poor performance.

    bool equalTime(const ClockType &) const;
};

void ClockType::setTime(int hr, int min, int sec)
{
    (hr >= 0 && hr <= 24) ? hour = hr : hour = 0;
    (min >= 0 && min <= 60) ? minutes = min : minutes = 0;
    (sec >= 0 && sec <= 60) ? seconds = sec : seconds = 0;
};
void ClockType::getTime(int &hr, int &min, int &sec) const
{
    hr = hour;
    min = minutes;
    sec = seconds;
};

void ClockType::printTime() const
{
    if (hour < 10)
    {
        cout << "0";
    };
    cout << hour << ":";

    if (minutes < 10)
    {
        cout << "0";
    };
    cout << minutes << ":";
    if (seconds < 10)
    {
        cout << "0";
    };
    cout << seconds << endl;
};

void ClockType::inc_sec()
{
    seconds++;
    if (seconds > 59)
    {
        seconds = 0;
        inc_min();
    }
}
void ClockType::inc_min()
{
    minutes++;
    if (minutes > 59)
    {
        minutes = 0;
        inc_hour();
    }
}
void ClockType::inc_hour()
{
    hour++;
    (hour > 23) ? hour = 0 : hour;
}
bool ClockType::equalTime(const ClockType &otherClock) const
{
    return (hour == otherClock.hour && minutes == otherClock.minutes && seconds == otherClock.seconds);
}
int main()
{

    // Declaration of objects of the ClockType data type;
    ClockType myClock, yourClock;
    return 0;
}