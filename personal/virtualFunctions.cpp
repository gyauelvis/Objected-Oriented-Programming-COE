#include <iostream>

using namespace std;

class PetType{

    private:
    string name;


    public:
    PetType(string name="");
    virtual void print()const;
};

void PetType::print()const{
    cout<<name<<endl;
}

PetType::PetType(string name){
    this->name=name;
}

class dogType:public PetType{

    private:
    string breed;

    public:
    void print()const;
    dogType(string name = "", string breed="");


};

void dogType::print() const{
    PetType::print();
    cout<<breed<<endl;
};

dogType::dogType(string name, string breed):PetType(name){
    this->breed=breed;
};

void callPrint(PetType& p){
    p.print();
}


int main()
{

    PetType pet("Lucky");
    dogType dog("Tommy", "German Shepherd");
    pet.print();
    cout << endl;
    dog.print();
    cout << "*** Calling the function callPrint ***"<< endl;
    callPrint(pet);
    cout << endl;
    callPrint(dog);
    cout << endl;
return 0;

}