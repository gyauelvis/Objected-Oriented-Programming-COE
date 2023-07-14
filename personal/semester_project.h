#include <iostream>
#include <fstream>
using namespace std;

class Inventory
{
    // private:
    fstream productFile;
    
    // public:
    void addProduct();
    void displayProduct();
    void modifyProducts();
    void deleteProduct();
    void searchProducts();
};

void Inventory::addProduct(){
    string productName;
    string refCode;
    int prodPrice;
    int quantity;

    cout<<"[ Press Enter Key after entering each detail ]";

    cout<<"Enter Product Name: ";
    cin>>productName;

    cout<<"Reference Code: ";
    cin>>refCode;

    cout<<"Price in GHS: "
    cin>>prodPrice;

    cout<<"Quantity: ";
    cin>>quantity;

    productFile.open("inventory_file.txt",ios::out); // Writting to a text file
    if(productFile.is_open()){
        productFile<<productName<<endl;
        productFile<<refCode<<endl;
        productFile<<prodPrice<<endl;
        productFile,,quantity<<endl;
    }
}


class Cashier
{
private:
    double totalCash, cashIn, costOfItem;

public:
    Cashier();
    Cashier(double totalAmount, double amountcashIn);
    Cashier(double totalAmount);
    int getBalance() const;
    
};
