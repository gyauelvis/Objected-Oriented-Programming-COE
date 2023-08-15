#include <iostream>
#include <string>
using namespace std;

// Going strictly by her question. I wanted to switch positions of some positions of some functions and member variable on her UML diagram but who am I? I no get MASTERS
class Fraction{
    protected:
        int numerator,denominator,whole_number;
    public:
    //Declaring a constructor(Not stated in the question but very necessary)
    Fraction(int new_numerator=0,int new_denominator=0,int new_whole_number=0);

    //Not stated in the question but necessary in my opinion
    void setValues(int new_numerator,int new_denominator,int new_whole_number){
        Fraction(new_numerator,new_denominator,new_whole_number);
    }

    // Decided to overload the = operator

        // Overloading the + operator
        Fraction operator +(Fraction op2){
            Fraction newFraction;
            if(whole_number == 0 && op2.whole_number == 0){
                //Performing fraction addition
                int lcm = denominator*op2.denominator;
                int numera = (denominator*op2.numerator) + (op2. denominator*numerator);
                newFraction.denominator = lcm;
                newFraction.numerator = numera;
            }else if(whole_number == 0 && op2.whole_number != 0){
                 // Then we have to change the farction in op2 to proper or improper whatever
                int newNumerator = (op2.denominator * op2.whole_number) + op2.numerator;
                int lcm = denominator*op2.denominator;
                int numera = (denominator*newNumerator) + (op2. denominator*numerator);
                newFraction.denominator = lcm;
                newFraction.numerator = numera;  
            }else if(whole_number != 0 && op2.whole_number == 0){
                int newNumerator = (denominator * whole_number) + numerator;
                int lcm = denominator*op2.denominator;
                int numera = (denominator*op2.numerator) + (op2. denominator*newNumerator);
                newFraction.denominator = lcm;
                newFraction.numerator = numera;
            }else if(whole_number != 0 && op2.whole_number != 0){
                int newNumerator = (denominator * whole_number) + numerator;
                int newNumerator1 = (op2.denominator * op2.whole_number) + op2.numerator;
                int lcm = denominator*op2.denominator;
                int numera = (denominator*newNumerator1) + (op2. denominator*newNumerator);
                newFraction.denominator = lcm;
                newFraction.numerator = numera;
            }
            
            cout<<newFraction.numerator<<"/"<<newFraction.denominator<<endl;
            return newFraction;
            
        }
        // Overloading the + operator
        Fraction operator *(Fraction op2){
            Fraction newFraction;
            // Checking if it is both are proper fractions or improper
            if(whole_number == 0 && op2.whole_number == 0){
                newFraction.numerator = numerator*op2.numerator;
                newFraction.denominator = denominator * op2.denominator;
            }else if(whole_number == 0 && op2.whole_number != 0){
               // Then we have to change the fraction in op2 to proper or improper whatever
                int newNumerator = (op2.denominator * op2.whole_number) + op2.numerator;
                
                newFraction.numerator = numerator*newNumerator;
                newFraction.denominator = denominator * op2.denominator; 
            }else if(whole_number != 0 && op2.whole_number == 0){
                // Then we have to change the farction in op2 to proper or improper whatever
                int newNumerator = (denominator * whole_number) + numerator;
        
                newFraction.numerator = numerator*newNumerator;
                newFraction.denominator = denominator * op2.denominator;
                
            }else if(whole_number != 0 && op2.whole_number != 0){
                int newNumerator = (denominator * whole_number) + numerator;
                
                int newNumerator1 = (op2.denominator * op2.whole_number) + op2.numerator;
                
                newFraction.numerator = newNumerator * newNumerator1;
                newFraction.denominator = denominator * op2.denominator;
            }
            return newFraction;
        }
        // Function that converts the fraction to decimals
        float toDecimal(){
            if(numerator == 0)
                return 0;
            else if(denominator == 0){
                cout<<"Math error"<<endl;
                return 0;
            }
            else{
                if(whole_number == 0){
                    cout<<numerator/denominator<<endl;
                    return (numerator/denominator);
                }
            }
        };
        // Show fraction
        virtual void showFraction(){
                cout<<numerator<<"/"<<denominator<<endl;
        };
    
};

//Definining the constructor
Fraction::Fraction(int new_numerator,int new_denominator,int new_whole_number){
    numerator = new_numerator;
    denominator = new_denominator;
    whole_number = new_whole_number;
}

//The ProperFraction derived class
class ProperFraction:public Fraction{
    public:
    ProperFraction(int new_numerator=0,int new_denominator=0,int new_whole_number=0);
};

ProperFraction::ProperFraction(int new_numerator,int new_denominator,int new_whole_number):Fraction(new_numerator,new_denominator,new_whole_number){};


class ImproperFraction:public Fraction{
    private:
    bool mixed;

    public:
    ImproperFraction(int new_numerator=0,int new_denominator=0,int new_whole_number=0);

    void toMixedFraction(){
        int mod = numerator % denominator;
        int intermid  = numerator - mod;
        whole_number = intermid/denominator;
        numerator = intermid;
    }
    void toImproperFraction(){
        numerator = (denominator * whole_number) + numerator;
        whole_number = 0;
    }
    void showFraction(){
        if(whole_number != 0)
            cout<<whole_number<<" whole number ";
        Fraction::showFraction();
    }
};

ImproperFraction::ImproperFraction(int new_numerator,int new_denominator,int new_whole_number):Fraction(new_numerator,new_denominator,new_whole_number){};

int main(){
    ProperFraction p1(1,2,0);
    p1.showFraction();//Should display 1/2
    (p1+p1);//should display 4/4
    float dec = (p1+p1).toDecimal(); //Should display 1
    ImproperFraction i(3,4,2);
    i.showFraction();//Should display 2 whole number 3/4
    ImproperFraction i2(5,3,0);
    i2.showFraction();//Should display 5/3
    (i + i2);
    p1+i2;
    i.setValues(3,4,2);
    
    
    
    return 0;
};