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

protected:
     fstream productFile;


public:
    void display_format_header();
    bool displayProduct();

};


void Shop::display_format_header() {
    cout << "\t\t\t\t" << setfill('-') << setw(65) << "" << "\n";
    cout << "\t\t\t\t" << left << setw(11) << "| ID"
         << setw(31) << "| Product Name"
         << setw(11) << "| Price"
         << setw(11) << "| Quantity"
         << "|\n";
    cout << "\t\t\t\t" << setfill('-') << setw(65) << "" << "\n"; // Add row separator
    cout << setfill(' ');
}

bool Shop::displayProduct() {
    vector<string> fileLines;
    int userChoice;
    bool refExist = false;
    string line;

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open()) {
        while (getline(productFile, line)) {
            fileLines.push_back(line);
        }

        productFile.close();
    }
    else {
        cout << "Error opening file";
        return false;
    }

    display_format_header();
    for (int i = 0; i < fileLines.size(); i += 4) {
        cout << "\t\t\t\t" << left << setw(11) << "| " + fileLines[i]
             << setw(31) << "| " + fileLines[i + 1]
             << setw(11) << "| " + fileLines[i + 2]
             << setw(11) << "| " + fileLines[i + 3]
             << "|\n";
        cout << "\t\t\t\t" << setfill('-') << setw(65) << "" << "\n"; // Add row separator
        cout << setfill(' ');
    }
    return true;
}

class Inventory:public Shop
{

private:
    int productRefNumber;

public:
    Inventory();
    bool admin();
    bool assignRefNumber();
    void addProduct();
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
    admin();
    displayProduct();

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
        cout << "\t\t\tError opening file." << endl;
        return false;
    }
    admin();
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

    cout << "\t\t\tProduct ID: ";
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
        cout << "\t\t\tError opening file";
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

            cout << "\t\t\tDeleted Successfully" << endl;
        }

        else
        {
            cout << "\t\t\tError deleting file." << endl;
            return false;
        }
        admin();
        return true;
    }
    else
    {
        cout << "\t\t\tReference ID not found" << endl;
        return false;
    }
}

// adminstration function
bool  Inventory::admin()
{
    int choice;
    admin: //label
    system("cls"); // clears the screen

    cout<<"\n"<<"\t\t\t\t_______________WELCOME TO THE ADMIN PAGE_______________\n";

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
        case 4:
            return true;
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
    bool login();
    void customer_page();
    void deposit();
    bool bmenu();
    void signUp();
    void buy();
    void receipt();
    double getCustomerBalance();
};

double Cashier::getCustomerBalance(){
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
        cout << "\t\t\tError opening file.\n";
        return 0 ;
    }

    int locOfDep = 0;
    for (int i = 0; i < loginCredentials.size(); i++)
    {
        if (loginCredentials[i] == userName)
        {
            locOfDep = i;
        }
    }

    return stoi(loginCredentials[locOfDep+2]);
}


bool Cashier::login()
{
    vector<string>loginCredentials;
    bool userNameExist= false,passwordExist =false;
    string line;
      cout<<"\t\t\t\t" << "___________________________________________________\n";
    cout<<"\n";
    cout <<"\t\t\t\t"<< "\t\t\t  Login Page\n";
    cout<<"\t\t\t\t" << "___________________________________________________\n";

menu:
    cout << "\n\t\t\tEnter your username: ";
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

        cout<<"\033[1;31m"<<"\t\t\tWrong Credentials"<<"\033[0m"<<endl;
        goto menu;

    }

    system("cls");
    customer_page();

}

void Cashier::signUp(){

 vector<string>loginCredentials;
 string line;
 string cpassword;
   cout<<"\t\t\t\t" << "___________________________________________________\n";
    cout<<"\n";
    cout <<"\t\t\t\t"<< "\t\t\t  SIGN UP\n";
    cout<<"\t\t\t\t" << "___________________________________________________\n";
 cout << "\n";
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
            cout<<"\033[1;31m"<<"\n\t\t\tUsername taken\n"<<"\033[0m"; //033[0m, color for red
            goto username_label;
            break;
        }

}
password_label:

  cout <<"\n\t\t\tCreate password[Minimum Characters: 8] : ";
  cin >> password;

  if(password.size() < 8){
        cout<<"\033[1;31m"<<"\n\t\t\tMinimum of 8 characters required"<<"\033[0m"<<endl;
        goto password_label;
    }

  cout<<"\n\t\t\tConfirm Password: ";
  cin>>cpassword;
  while(cpassword!=password){
    cout<<"\033[1;31m"<<"\n\t\t\tPassword does not match\n"<<"\033[0m";
    goto password_label;
  }



    cout<<"\n\t\t\tInitial Deposit: ";
    cin>>amountInAccount;

    loginFile.open("login_file.txt",ios::app);
    if(loginFile.is_open()){
        loginFile<<userName<<endl;
        loginFile<<password<<endl;
        loginFile<<amountInAccount<<endl;
        loginFile.close();
        cout<<"\033[32m"<<"\n\t\t\tAccount Created Successfully"<<"\033[0m"<<endl;
    }

    system("cls");
    login();

}


//deposit
void Cashier::deposit()
{
    double new_amount;

    cout << "\n\t\tHow much would you like to deposit: ";
    cin >> new_amount;

    vector<string> loginCredentials;
    string line;


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
    system("cls");
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
    cout<<"\t\t\t\t\t      |    [1] LOGIN         |\n";
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
    bmenu:
    int choice;

    cout << "\t\t\t\t  Hey, " << userName << "\t\t\t\t\t\t|GHS " << fixed << setprecision(2) << getCustomerBalance() << "|" << endl;
    cout << "\t\t\t\t\t                             \n";
    cout << "\t\t\t\t\t      |    [1] DEPOSIT       |\n";
    cout << "\t\t\t\t\t      |    [2] BUY           |\n";
    cout << "\t\t\t\t\t      |    [3] MAIN MENU     |\n";
    cout << "\t\t\t\t\t                             \n";
    cout << "\t\t\t Option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            system("cls");
            deposit();
            goto bmenu;
            break;
        case 2:
            system("cls");
            buy(); // Call the function to handle the "BUY" functionality
            goto bmenu; // Redirect back to the customer menu after the "BUY" process
            break;
        case 3:
            return; // Exit the function and return to the main menu
            break;
        default:
            system("cls");
            std::cout << "\n\t\t\tInvalid Option" << std::endl;
            goto bmenu;
    }
}


void Cashier::buy() {
    displayProduct();
    string productId;
    cout << "\n\t\t\tEnter the ID of the product you want to buy: ";
    cin >> productId;

    vector<string> fileLines;
    string line;
    bool productFound = false;

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open()) {
        while (getline(productFile, line)) {
            fileLines.push_back(line);
        }
        productFile.close();
    } else {
        cout << "\n\t\t\tError opening the file." << endl;
        return;
    }

    // Find the product in the inventory
    for (int i = 0; i < fileLines.size(); i += 4) {
        if (fileLines[i] == productId) {
            productFound = true;
            int quantityAvailable = stoi(fileLines[i + 3]);
            int price = stoi(fileLines[i + 2]);

            // Check if the product is available in sufficient quantity
            if (quantityAvailable > 0) {
                cout << "\n\t\t\tProduct found: " << fileLines[i + 1] << "\n";
                cout << "\n\t\t\tPrice: GHS " << price << "\n";
                cout << "\n\t\t\tEnter quantity to buy: ";
                int quantityToBuy;
                cin >> quantityToBuy;

                // Check if the requested quantity is available
                if (quantityToBuy <= quantityAvailable) {
                    double totalCost = price * quantityToBuy;

                    // Check if the customer has enough balance to make the purchase
                    double customerBalance = getCustomerBalance();
                    if (totalCost <= customerBalance) {
                        // Update customer's balance
                        amountInAccount -= totalCost;

                        // Update product quantity in the inventory
                        quantityAvailable -= quantityToBuy;
                        fileLines[i + 3] = to_string(quantityAvailable);

                        // Write the updated data back to the file
                        productFile.open("inventory_file.txt", ios::out);
                        if (productFile.is_open()) {
                            for (const string& modifiedLine : fileLines) {
                                productFile << modifiedLine << "\n";
                            }
                            productFile.close();
                        } else {
                            cout << "\n\t\t\tError writing to the file." << endl;
                            return;
                        }

                        // Update customer balance in the login file
                        vector<string> loginCredentials;
                        productFile.open("login_file.txt", ios::in);
                        if (productFile.is_open()) {
                            while (getline(productFile, line)) {
                                loginCredentials.push_back(line);
                            }
                            productFile.close();
                        } else {
                            cout << "\n\t\t\tError opening the file." << endl;
                            return;
                        }

                        int locOfDep = 0;
                        for (int i = 0; i < loginCredentials.size(); i++) {
                            if (loginCredentials[i] == userName) {
                                locOfDep = i;
                            }
                        }

                        // Update the user's balance in the vector
                        loginCredentials[locOfDep + 2] = to_string(amountInAccount);

                        // Write the updated login credentials back to the file
                        productFile.open("login_file.txt", ios::out);
                        if (productFile.is_open()) {
                            for (int i = 0; i < loginCredentials.size(); i++) {
                                productFile << loginCredentials[i] << "\n";
                            }
                            productFile.close();
                        } else {
                            cout << "\n\t\t\tError writing to the file." << endl;
                            return;
                        }
                        system("cls");

                        cout << "\n\t\t\tPurchase successful." << endl << "\n";
                        cout << "\n\t\t\tReceipt:" << endl << "\n";
                        cout << "\t\t\t+-----------------------+-----------+-------+---------------+---------------+" << endl;
                        cout << "\t\t\t|       Product         | Quantity  | Price | Total Cost    | Remaining Bal |" << endl;
                        cout << "\t\t\t+-----------------------+-----------+-------+---------------+---------------+" << endl;
                        cout << left << fixed << setprecision(2);
                        cout << "\t\t\t| " << setw(22) << fileLines[i + 1] << " | " << setw(9) << quantityToBuy << "| " << setw(5) << price
                        << " | " << setw(13) << totalCost << " | " << setw(13) << getCustomerBalance() << " |" << endl;
                        cout << "\t\t\t+-----------------------+-----------+-------+---------------+---------------+" << endl << "\n";



                    } else {
                        cout << "\n\t\t\tInsufficient balance. Please deposit more funds to make the purchase." << endl;
                    }
                } else {
                    cout << "\n\t\t\tInsufficient quantity available in the inventory." << endl;
                }
            } else {
                cout << "\n\t\t\tProduct is out of stock." << endl;
            }
            break; // Exit the loop as we found the product
        }
    }

    if (!productFound) {
        cout << "\n\t\t\tProduct not found." << endl;
    }
}

