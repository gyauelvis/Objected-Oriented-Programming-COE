// Todos
// Gettingccreative if time is permitted we could convert all the info in text file so that if somebody manually opens up the text file they wouldn't have access to our info
// Formatting the output
// Reference id should be program generated not entered by user

#include <iostream>
#include <fstream>
#include <string> // For using the getline()
using namespace std;

class Inventory
{
    // private:
    int productRefNumber;
    fstream productFile;

    // public:
    Inventory();
    void addProduct();
    void displayProduct();
    void modifyProducts();
    void deleteProduct();
    void searchProducts();
};

Inventory::Inventory()
{
    productRefNumber = 0;

    productFile.open("inventory_file.txt", ios::out); // Writting to a text file
    if (productFile.is_open())
    {
        productFile << "List of Available Products\n";
    };
}

void Inventory::addProduct()
{

    string productName;
    int prodPrice, quantity;

    cout << "[ Press Enter Key after entering each detail ]" << endl;

    cout << "Product ID: " << productRefNumber++ << endl
         << "Enter Product Name: ";
    cin >> productName;

    cout << "Price in GHS: ";
    cin >> prodPrice;

    cout << "Quantity: ";
    cin >> quantity;

    productFile.open("inventory_file.txt", ios::app); // Writting to a text file
    if (productFile.is_open())
    {
        productFile << productName << endl;
        productFile << productRefNumber << endl;
        productFile << prodPrice << endl;
        productFile << quantity << endl;
        productFile << "\n";
        productFile.close();
    }
}

void Inventory::displayProduct()
{

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        string line;
        // The getline function reads a line of text from the text file and assigns it to the string var
        while (getline(productFile, line))
        {
            cout << line << endl;
        }
        productFile.close();
    }
}

void Inventory::modifyProducts()
{

    int userChoice;
    bool refExist = false;
    string refCode, line; // line keeps the individual line the pc reads.
    cout << "[ Press Enter Key after entering each detail ]" << endl;
    cout << "Enter the reference code of the product you would want to modify" << endl;
    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        while (getline(productFile, line))
        {
            if (line == refCode)
            {
                refExist = true;
                break;
            }
        }
        productFile.close();
    }
    if (refExist)
    {
        cout << "What do you want to modify" << endl
             << "1. Product Name" << endl
             << "2. Price" << endl
             << "3. Quantity" << endl;
        cin >> userChoice;
    }
}

// class Cashier
// {
// private:
//     double totalCash, cashIn, costOfItem;

// public:
//     Cashier();
//     Cashier(double totalAmount, double amountcashIn);
//     Cashier(double totalAmount);
//     int getBalance() const;
// };
