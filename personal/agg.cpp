#include <iostream>
#include <string>
using namespace std;

class PersonType{
    private:
    string firstName;
    string lastName;

    public:
    void setName(string firstName,string lastName);
    PersonType(string new_firstName="",string new_lastName="");
    void display();

};

void PersonType::setName(string firstName,string lastName){
    this->firstName = firstName;
    this->lastName= lastName;
}

PersonType::PersonType(string new_firstName,string new_lastName){
    setName(new_firstName,new_lastName);
}

void PersonType::display(){
    cout<<"Name: "<<firstName<<endl<<"Last Name: "<<lastName<<endl;
}

class dateType{
    private:
    int year,month,day;

    public:
    void setDate(int year,int month,int day);
    dateType(int new_year = 1990,int new_month = 1,int new_day=1);
};

void dateType::setDate(int year,int month,int day){
    (month>0 && month<=12)?this->month = month:this->month = 1;
    (day>0 && day<=31)?this->day = day:this->day = day= 1;
    (year>0 && year<=2023)?this->year = year:this->year = 1990;
};
dateType::dateType(int new_year, int new_month, int new_day){
    setDate(new_year, new_month, new_day);
}

class PersonalInfo{
    PersonType person;
    dateType date;
    int id;

    public:
    PersonalInfo(string new_firstName="",string new_lastName="",int new_year = 1990,int new_month = 1,int new_day=1,int new_id);
};

PersonalInfo::PersonalInfo(string new_firstName,string new_lastName,int new_year,int new_month,int new_day,int new_id):date(new_year,new_month,new_day),person(new_firstName,new_lastName){
    id = new_id;
};



