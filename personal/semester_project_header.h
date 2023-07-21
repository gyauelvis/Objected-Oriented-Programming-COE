// Todos
// input error handling
// Gettingccreative if time is permitted we could convert all the info in text file so that if somebody manually opens up the text file they wouldn't have access to our info
// Formatting the output
// Outputting a sorry message when the user wants to modify the file but enters a wrong id

#include <iostream>
#include <vector>
#include <fstream>
#include <string> // For using the getline()
#include <iomanip>
#include <cstdlib> //header for a system function
// #include <windows.h>
using namespace std;

class Inventory
{
private:
    int productRefNumber;
    fstream productFile;

public:
    Inventory();
    void menu();
    void admin();
    bool assignRefNumber();
    void addProduct();
    bool displayProduct();
    bool modifyProducts();
    bool deleteProduct();
    void display_format_header();
};

Inventory::Inventory() : productRefNumber(1){};

bool Inventory::assignRefNumber()
{
    vector<string> refNumber_vector;
    string line;

    productFile.open("inventory_file.txt", ios::in);

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
    };
    return true;
}
void Inventory::addProduct()
{
    // checking if the inventory file is open then it closes it
    if (productFile.is_open())
    {
        productFile.close();
    }

    displayProduct();

    string productName;
    int prodPrice, quantity,numberOfItems;


    cout << "\t\t\t\t[ Press Enter Key after entering each detail ]\n\n";

    cout<<"How many product do you want to add?: ";
    cin>>numberOfItems;
    //validate inputs
    for(int i = 0;i<numberOfItems;i++){

    assignRefNumber();

    cout << "\t\t\t\tProduct ID: " << productRefNumber << endl
         << "\t\t\t\tEnter Product Name: ";
    cin >> productName;

    cout << "\t\t\t\tPrice in GHS: ";
    cin >> prodPrice;

    cout << "\t\t\t\tQuantity: ";
    cin >> quantity;
    cin.ignore();// Clears input buffer

    }






    if (productFile.is_open())
    {
        productFile << productRefNumber << "\n";
        productFile << productName << "\n";
        productFile << prodPrice << "\n";
        productFile << quantity << "\n";
        productFile.close();

        system("cls");

        // Changing color of text to green
        // system("Color 0A");

        cout << "\t\t\t\tProduct Added Sucessfully\n\n";

        // system("Color 07");
    }
    else
    {
        cout << "Error opening file";
    }
}

void Inventory::display_format_header()
{
    cout <<"\t\t\t\t"<< left << setw(10) << "ID"
         << setw(20) << "Product Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity"
         << "\n";
    cout <<"\t\t\t\t"<< setfill('-') << setw(50) << ""
         << "\n";
    cout << setfill(' ');
}

bool Inventory::displayProduct()
{

    vector<string> fileLines;
    int userChoice;
    bool refExist = false;
    string line;

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

    display_format_header();
    for (int i = 0; i < fileLines.size(); i += 4)
    {

        cout <<"\t\t\t\t"<< left << setw(10) << fileLines[i]
             << setw(20) << fileLines[i + 1]
             << setw(10) << fileLines[i + 2]
             << setw(10) << fileLines[i + 3] << "\n";
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

    displayProduct();

    cout << "\t\tEnter ID of the product you want to modify: ";
    cin >> refCode;
    cin.ignore();

    // This loops goes through the vector to see if the product id the user entered exists
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

// Function definition for deleteProduct

bool Inventory::deleteProduct()
{

    displayProduct();
    vector<string> fileLines;
    bool refExist = false;
    string line, refCode;

    // will help us delete the product
    int product;

    cout << "Product ID: ";
    cin >> refCode;

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

    // This loops goes through the vector to see if the product id the user entered exists
    for (int i = 0; i < fileLines.size(); i += 4)
    {
        if (fileLines[i] == refCode)
        {
            refExist = true;
            product = i;
            break;
        }
    }
    if (refExist == true)
    {

        fileLines.erase(fileLines.begin() + product, fileLines.begin() + (product + 4));

        productFile.open("inventory_file.txt", ios::out); // overwriting the whole file

        if (productFile.is_open())
        {

            for (const string &modifiedLine : fileLines)
            {
                productFile << modifiedLine << "\n";
            }

            productFile.close();

            cout << "Deleted Successfully" << endl;
        }

        else
        {
            cout << "Error deleting file." << endl;
            return false;
        }
        return true;
    }
    else
    {
        cout << "Reference ID not found" << endl;
        return false;
    }
}

//main menu function
void Inventory::menu()
{
    main_menu:  // label
    int choice;
    string username;
    string password;

    //Styling the main menu page
    cout<<"\t\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t\t                                     \n";
    cout<<"\t\t\t\t\t                                  \n";
    cout<<"\t\t\t\t\t    SUPERMARKET MAIN MENU         \n";
    cout<<"\t\t\t\t\t                                   \n";
    cout<<"\t\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t\t                                     \n";
    cout<<"\t\t\t\t\t      |    [1] ADMIN    |\n";
    cout<<"\t\t\t\t\t      |                 |\n";
    cout<<"\t\t\t\t\t      |    [2] BUYER    |\n";
    cout<<"\t\t\t\t\t      |                 |\n";
    cout<<"\t\t\t\t\t      |    [3] EXIT     |\n";
    cout<<"\t\t\t\t\t                                      \n";
    cout<<"\n\t\t\t\tPlease select: ";
    cin >>choice;
    cout<<"\n";
    switch(choice)
    {
    case 1:
        cout<<"\t\t\t\t\t---------Login Page--------------\n";
        cout<<"\n\t\t\tusername: ";
        cin>>username;
        cout<<"\n\n\t\t\tPassword: ";
        cin>>password;

        if (username=="admin" && password=="password"){
           admin();
        }
        else
        {
            cerr<<"Invalid email/password";
        }
        break;
    case 2:
            //buyer();
            break;
    case 3:
            exit(0);
            break;
    default:
            cout<<"Please select from the given options";
            goto main_menu;
    }
}



// adminstration function
void  Inventory::admin()
{
    int choice;
    admin: //label
    system("cls"); // clears the screen

    cout<<"\n"<<"\t\t\t\t_________WELCOME TO THE ADMIN PAGE_________\n";
    cout<<endl;
    displayProduct();

    cout<<"\n\t\t\t\t\t|______[1] ADD PRODUCT________|\n";
    cout<<"\t\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t\t|______[2] MODIFY PRODUCT_____|\n";
    cout<<"\t\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t\t|______[3] DELETE PRODUCT_____|\n";
    cout<<"\t\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t\t|______[4] BACK TO MAIN MENU__|\n";

    cout<<endl;
    cout<<"\n\tPlease enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            addProduct();
            break;

        case 2:
            modifyProducts();
            break;

        case 3:
            deleteProduct();
            break;

        case 4:
            menu();
            break;

        default:
            cout<<"Invalid choice!!";
            goto admin;
    }

}
