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


class Shop{

private:

public:
    void display_format_header();

};


void Shop::display_format_header()
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



class Inventory:public Shop
{

private:
    int productRefNumber;
    fstream productFile;

public:
    Inventory();
    void admin();
    bool assignRefNumber();
    void addProduct();
    bool displayProduct();
    bool modifyProducts();
    bool deleteProduct();


//friend class Cashier;
};

Inventory::Inventory() : productRefNumber(1){};

// We will understand
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
        productFile.close();
    }
    else
    {
        cout << "Error Assigning Reference Number";
        return false;
    }

    if (refNumber_vector.size() == 0)
    {
        productRefNumber = 1;
    }
    else
    {
        int i = 0;
        while (i < refNumber_vector.size())
        {
            if (productRefNumber == stoi(refNumber_vector[i]))
            {
                productRefNumber++;
                i = 0; // Reset to check from the beginning again
            }
            else
            {
                i += 4; // Move to the next product entry
            }
        }
    }
    return true;
}




void Inventory::addProduct() {
    string productName;
    int prodPrice, quantity;

    assignRefNumber();
    cout<<"\n\t\tProduct ID: "<<productRefNumber<<endl;
    cout<<"\n";
    cout << "\t\tEnter Product Name: ";
    //cin.ignore(); // Ignore the newline character left in the input buffer
    cin>>productName;
    cout<<"\n";
    cout << "\t\tPrice in GHS: ";
    cin >> prodPrice;
    cout<<"\n";

    cout << "\t\tQuantity: ";
    cin >> quantity;
    cout<<"\n";

    productFile.open("inventory_file.txt", ios::app); // Writing to a text file
    if (productFile.is_open()) {
        productFile << productRefNumber << endl;
        productFile << productName << endl;
        productFile << prodPrice << endl;
        productFile << quantity << endl;

        // Flush the buffer to ensure data is written to the file immediately
        productFile.flush();

        // Close the file
        productFile.close();
    }
    else {
        cout << "Error opening the file." << endl;


    }

    displayProduct();
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

    cout << "\n\t\tEnter ID of the product you want to modify: ";
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
        cout << "\t\tProduct not found." << endl;
        return false;
    }

    cout << "\t\tWhat do you want to modify?" << endl
         << "\t\t1. Product Name" << endl
         << "\t\t2. Price" << endl
         << "\t\t3. Quantity" << endl;
    cin >> userChoice;

    if (userChoice == 1)
    {
        string new_product_name;
        cout << "\t\tNew Product Name: ";
        cin.ignore();
        getline(cin, new_product_name);
        fileLines[stoi(refCode) * 4 - 3] = new_product_name;
    }
    else if (userChoice == 2)
    {
        string new_price;
        cout << "\t\tNew Price: ";
        cin >> new_price;
        fileLines[stoi(refCode) * 4 - 2] = new_price;
    }
    else if (userChoice == 3)
    {
        string new_quantity;
        cout << "\t\tNew Quantity: ";
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
        system("cls");
        displayProduct();
        cout << "\n\t\tModification successful." << endl;
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
    cout<<"\n\t\tPlease enter your choice: ";
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

        default:
            cout<<"Invalid choice!!";
            goto admin;
    }

}




class Cashier:public Shop{

private:
    string prodName,userName,password, cpassword;
    int prodQuantity;
    double amountInAccount, showAmount;
    fstream loginFile;
    fstream productFile;

public:
    void display_format_header();
    bool login();
    void customer_page();
    void deposit();
    bool bmenu();
    void signUp();
    void addCart();
    void buy();
    void receipt();
    bool displayProd();
    void buyer();

};

void Cashier::display_format_header()
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

bool Cashier::login()
{
    vector<string>loginCredentials;
    bool userNameExist= false,passwordExist =false;
    string line;
    cout << "\t\t\t\t________________________LOGIN PAGE______________________\n";
    cout << endl;

menu:
    cout << "\t\t\tEnter your username: ";
    cin >> userName;
    cout <<"\n\t\t\tEnter your password: ";
    cin >> password;
    loginFile.open("login_file.txt",ios::in);
    if(loginFile.is_open()){
            while(getline(loginFile,line)){
                loginCredentials.push_back(line);
            }
            loginFile.close();
    }else{
        cout<<"Error opening file";
        return false;

    }

    for(int i =0;i<loginCredentials.size();i+=3){

        if(loginCredentials[i] == userName){
                userNameExist = true;

        }
        if(loginCredentials[i+1]==password){
            passwordExist = true;

        }

    }

    if(userNameExist==true&&passwordExist ==true){


    }else{

        cout<<"\033[1;31m"<<"\t\t\tWrong Credenetials"<<"\033[0m"<<endl;
        goto menu;

    }

    system("cls");
    customer_page();

}

void Cashier::signUp(){

 vector<string>loginCredentials;
 string line;
 string cpassword;
 cout << "\t\t\t\t________________________SIGN UP______________________\n";
 cout << endl;
username_label:
 cout << "\n\t\t\tCreate Username: ";
 cin >> userName;

loginFile.open("login_file.txt",ios::in);
if(loginFile.is_open()){
        while(getline(loginFile,line)){
            loginCredentials.push_back(line);
        }
        loginFile.close();
    }
 for(int i = 0;i<loginCredentials.size();i+=3){
        if(userName == loginCredentials[i]){
            cout<<"\033[1;31m"<<"\n\t\tUsername taken\n"<<"\033[0m"; //033[0m, color for red
            goto username_label;
            break;
        }

}
password_label:

  cout <<"\n\t\tCreate password[Minimum Characters: 8] : ";
  cin >> password;

  if(password.size() < 8){
        cout<<"\033[1;31m"<<"\n\t\tMinimum of 8 characters required"<<"\033[0m"<<endl;
        goto password_label;
    }

  cout<<"\n\t\tConfirm Password: ";
  cin>>cpassword;
  while(cpassword!=password){
    cout<<"\033[1;31m"<<"\n\t\tPassword does not match\n"<<"\033[0m";
    goto password_label;
  }



    cout<<"\n\t\tInitial Deposit: ";
    cin>>amountInAccount;

    loginFile.open("login_file.txt",ios::app);
    if(loginFile.is_open()){
        loginFile<<userName<<endl;
        loginFile<<password<<endl;
        loginFile<<amountInAccount<<endl;
        loginFile.close();
    }

}


//deposit
void Cashier::deposit()
{
    vector<string> loginCredentials;
    string line;
    double new_amount;

    cout << "\n\t\tHow much would you like to deposit: ";
    cin >> new_amount;

    amountInAccount += new_amount;
    cout <<"\033[32m"<< "\n\t\tDeposit successful\n"<< "\033[0m";

    loginFile.open("login_file.txt", ios::in);
    if (loginFile.is_open())
    {
        while (getline(loginFile, line))
        {
            loginCredentials.push_back(line);
        }
        loginFile.close();
    }
    else
    {
        cout << "Error opening file.\n";
        return;
    }

    int locOfDep = 0;
    for (int i = 0; i < loginCredentials.size(); i++)
    {
        if (loginCredentials[i] == userName)
        {
            locOfDep = i;
        }
    }

    // Update the user's balance in the vector
    loginCredentials[locOfDep + 2] = to_string(amountInAccount);

    loginFile.open("login_file.txt", ios::out); // Open file to write
    if (loginFile.is_open())
    {
        for (int i = 0; i < loginCredentials.size(); i++)
        {
            loginFile << loginCredentials[i] << endl;
        }
        loginFile.close();
        cout<<"\033[32m" << "\n\t\tDeposit successful.\n"<<"\033[0m";  // \033[32m color green
    }
    else
    {
        cout << "\n\t\tError writing to file.\n";
    }
}
bool Cashier::displayProd()
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

bool Cashier::bmenu(){
    int choice;
    system("cls");

buyerMenu:
    //Styling the main menu page
    cout<<"\t\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t\t                                     \n";
    cout<<"\t\t\t\t\t                                  \n";
    cout<<"\t\t\t\t\t            CUSTOMER MENU         \n";
    cout<<"\t\t\t\t\t                                   \n";
    cout<<"\t\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t\t                                     \n";
    cout<<"\t\t\t\t\t      |    [1]LOGIN          |\n";
    cout<<"\t\t\t\t\t      |                      |\n";
    cout<<"\t\t\t\t\t      |    [2] SIGN UP       |\n";
    cout<<"\t\t\t\t\t      |                      |\n";
    cout<<"\t\t\t\t\t      |    [3] MAIN MENU     |\n";
    cout<<"\t\t\t\t\t                                      \n";
    cout<<"\n\t\t\t\tPlease select: ";
    cin>>choice;

    switch(choice){
        case 1:
            system("cls");
            login();
            break;
        case 2:
            system("cls");
            signUp();
            break;
        case 3:
            return false;
            break;
        default:
            cout<<"Invalid Option"<<endl;
            system("cls");
            goto buyerMenu;
    }
}


void Cashier::customer_page()
{
    vector<string>loginCredentials;
    string line;
    loginFile.open("login_file.txt", ios::in);
    if (loginFile.is_open())
    {
        while (getline(loginFile, line))
        {
            loginCredentials.push_back(line);
        }
        loginFile.close();
    }
    else
    {
        cout << "Error opening file.\n";
        return;
    }

    int locOfDep = 0;
    for (int i = 0; i < loginCredentials.size(); i++)
    {
        if (loginCredentials[i] == userName)
        {
            locOfDep = i;
        }
    }

    int choice;
    cout<<"\n\t\t Hi, "<<userName<<"\t\t\t\t\t\t\t\t\t\t|GHS "<<stof(loginCredentials[locOfDep+2])<<"|"<<endl;
    cout<<"\t\t\t\t\t                             \n";
    cout<<"\t\t\t\t\t      |    [1] DEPOSIT       |\n";
    cout<<"\t\t\t\t\t      |                      |\n";
    cout<<"\t\t\t\t\t      |    [2] BUY           |\n";
    cout<<"\t\t\t\t\t      |                      |\n";
    cout<<"\t\t\t\t\t      |    [3] MAIN MENU     |\n";
    cout<<"\t\t\t\t\t                                      \n";
    cout<<"\t\t\t Option: ";
    cin>>choice;

    switch(choice){
        case 1:
            system("cls");
            deposit();
            break;
        case 2:
            system("cls");
            //buyer();
            break;
        case 3:
            break;
    }


}





