// Aggregation relation of classes
#include <iostream>
using namespace std;
// Class Person Type keeping track of a person's name
class PersonType{
private:
string firstName;
string lastName;

public:
    PersonType():firstName(""),lastName(""){};

    PersonType(string new_firstName,string new_lastName){
        firstName = new_firstName;
        lastName = new_lastName;
    }

    void setName(string new_firstName,string new_lastName){
        firstName = new_firstName;
        lastName = new_lastName;
    }

    void displayName(){
        cout<<"First Name: "<<firstName<<" Last Name: "<<lastName<<endl;
    }
};

// Class Date type keeping track of a person's date of birth
class dateType{
    private:
        int dMonth,dDay,dYear;
    public:
    void setDate(int month, int day, int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    void printDate()const;
    dateType(int year = 1,int month=1,int year=1990);

};

void dateType::setDate(int month, int day, int year){
    (month>0 && month<=12)?dMonth = month:dDay = 1;
    (day>0 && day<=31)?dDay = day:dDay = 1;
    (year>0 && year<=2023)?dYear = year:dYear = 1990;
}
int dateType::getMonth()const{ return dMonth; }
int dateType::getDay()const{ return dDay; }
int dateType::getYear()const{ return dYear; }
void dateType::printDate()const{
    cout<<dDay<<"/"<<dMonth<<"/"<<dYear<<endl;
}
dateType::dateType(int day ,int month,int year){
    (month>0 && month<=12)?dMonth = month:dDay = 1;
    (day>0 && day<=31)?dDay = day:dDay = 1;
    (year>0 && year<=2023)?dYear = year:dYear = 1990;

}

// This class makes use of the two class above. It keeps the personal info of an individual. 
// Given every person has a name and date of birth



class PersonalInfo{
    private:
    string firstName,
}





























// class PersonalInfo{
//     private:
//     // The person object of type PersonType - Referring to the previous class
//         PersonType person;
//     // The date object of type dateType - Referring to the previous class
//         dateType date;
        
//         int person_id;
//     public:
//         PersonalInfo(string fName = "", string lName = "", int person_id = 0, int day=1,int month=1,int year=1990);
//         void setPersonalInfo(string fName, string lName, int person_id, int day,int month,int year);
//         void printPersonalInfo()const;
// };

// PersonalInfo::PersonalInfo(string fName, string lName, int id, int day,int month,int year):person(fName,lName),
// date(day,month,year){
//     person_id = id
// }
// void PersonalInfo::setPersonalInfo(string fName, string lName, int person_id, int day,int month,int year){
//     person.setName(fName,lName);
//     date.setDate(day,month,year);
//     person_id = id;
// };

// void PersonalInfo::printPersonalInfo()const{
//     person.displayName();
//     date.printDate();
// }