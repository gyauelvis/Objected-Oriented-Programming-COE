// Todos
// Gettingccreative if time is permitted we could convert all the info in text file so that if somebody manually opens up the text file they wouldn't have access to our info
// Formatting the output
// Outputting a sorry message when the user wants to modify the file but enters a wrong id

#include <iostream>
#include <vector>
#include <fstream>
#include <string> // For using the getline()
#include <limits>
using namespace std;

class Inventory
{
    // private:
    int productRefNumber;
    fstream productFile;

public:
    Inventory();
    bool assignRefNumber();
    void addProduct();
    void displayProduct();
    bool modifyProducts();
    void deleteProduct();
    void searchProducts();
};

Inventory::Inventory() : productRefNumber(0){};

bool Inventory::assignRefNumber()
{
    productRefNumber++;
    vector<string> refNumber_vector;
    string line;
    productFile.open("inventory.txt", ios::in);
    if (productFile.is_open())
    {
        while (getline(productFile, line))
        {
            refNumber_vector.push_back(line);
        }
    }
    else
    {
        cout << "Error Assigning Reference Number";
        return false;
    }

    int i = 0;
    while (i < refNumber_vector.size())
    {
        if (productRefNumber == stoi(refNumber_vector[i]))
        {
            productRefNumber++;
        }
        i += 4;
        productFile.close();
    };
}
void Inventory::addProduct()
{
    string productName;
    int prodPrice, quantity;

    cout << "[ Press Enter Key after entering each detail ]" << endl;

    cout << "Product ID: " << ++productRefNumber << endl
         << "Enter Product Name: ";
    cin >> productName;

    cout << "Price in GHS: ";
    cin >> prodPrice;

    cout << "Quantity: ";
    cin >> quantity;
    cin.ignore();

    if (productFile.is_open())
    {
        productFile.close();
    }

    productFile.open("inventory_file.txt", ios::app); // Writing to a text file
    if (productFile.is_open())
    {
        productFile << productRefNumber << "\n";
        productFile << productName << "\n";
        productFile << prodPrice << "\n";
        productFile << quantity << "\n";
        productFile.close();
    }
    else
    {
        cout << "Error opening file";
    }
}

void Inventory::displayProduct()
{

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        productFile.seekg(0, ios::beg); // Reset the file cursor to the beginning
        string line;
        cout << "List of Available Products\n";
        while (getline(productFile, line))
        {
            cout << line << endl;
        }
        productFile.close();
    }
    else
    {
        cout << "Error opening file";
    }
}

bool Inventory::modifyProducts()
{
    vector<string> fileLines;
    int userChoice;
    bool refExist = false;
    string line, refCode;

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        while (getline(productFile, line))
        {
            fileLines.push_back(line);
        }

        productFile.close();
    }
    else
    {
        cout << "Error opening file";
        return false;
    }

    cout << "List of Available Products" << endl;
    for (int i = 0; i < fileLines.size(); i += 4)
    {
        cout << "Product ID: " << fileLines[i] << endl;
        cout << "Product Name: " << fileLines[i + 1] << endl;
        cout << "Price: " << fileLines[i + 2] << endl;
        cout << "Quantity: " << fileLines[i + 3] << endl;
        cout << "---------------------------" << endl;
    }

    cout << "Enter the product ID or reference code of the product you want to modify: ";
    cin >> refCode;
    cin.ignore();

    for (int i = 0; i < fileLines.size(); i += 4)
    {
        if (fileLines[i] == refCode)
        {
            refExist = true;
            break;
        }
    }

    if (!refExist)
    {
        cout << "Product not found." << endl;
        return false;
    }

    cout << "What do you want to modify?" << endl
         << "1. Product Name" << endl
         << "2. Price" << endl
         << "3. Quantity" << endl;
    cin >> userChoice;

    if (userChoice == 1)
    {
        string new_product_name;
        cout << "Current Product Name: " << fileLines[stoi(refCode) * 4 - 3] << endl;
        cout << "New Product Name: ";
        cin.ignore();
        getline(cin, new_product_name);
        fileLines[stoi(refCode) * 4 - 3] = new_product_name;
    }
    else if (userChoice == 2)
    {
        string new_price;
        cout << "Current Price: " << fileLines[stoi(refCode) * 4 - 2] << endl;
        cout << "New Price: ";
        cin >> new_price;
        fileLines[stoi(refCode) * 4 - 2] = new_price;
    }
    else if (userChoice == 3)
    {
        string new_quantity;
        cout << "Current Quantity: " << fileLines[stoi(refCode) * 4 - 1] << endl;
        cout << "New Quantity: ";
        cin >> new_quantity;
        fileLines[stoi(refCode) * 4 - 1] = new_quantity;
    }
    else
    {
        cout << "Wrong Option" << endl;
        return false;
    }

    productFile.open("inventory_file.txt", ios::out); // overwriting the whole file
    if (productFile.is_open())
    {
        for (const string &modifiedLine : fileLines)
        {
            productFile << modifiedLine << "\n";
        }
        productFile.close();
        cout << "Modification successful." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
        return false;
    }

    return true;
}
