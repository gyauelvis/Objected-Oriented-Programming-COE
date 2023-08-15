#include <iostream>
using namespace std;

class Base{
    public:
    virtual void show(){
        cout<<"Base"<<endl;
    }
};

class Derv1:public Base{
    public:

    void show(){
        cout<<"Derv2"<<endl;
    }
};


int main(){

    Derv1 dv1;
    Derv1 dv2;
    Base *ptr;

    ptr = &dv1;
    ptr->show();

    return 0;
}



