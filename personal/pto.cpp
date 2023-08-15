#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
    string name;
    public:
    void setName(){
        cout<<"Name:";
        cin>>name;
    }

    void printName(){
        cout<<name<<endl;
    }

};

int main(){
    Person *personPointer[100];
    string c;
    int n  = 0;
    do{
        personPointer[n]=new Person;
        personPointer[n]->setName();
        n++;
        cout<<"Continue(Y/N)";
        cin>>c;
    }while(c == "Y");

    for(int j =0;j<n;j++){
        personPointer[j]->printName();
    };

    return 0;
}
