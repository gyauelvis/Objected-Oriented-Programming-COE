#include <iostream>
#include "main.h"
using namespace std;


int main()
{
    Inventory shop1;
    Cashier shop1_customer;
    main_menu:  // label
    int choice;
    string username;
    string password;
    bool returnToMainMenu = false; // Variable to track whether to return to the main menu

    //Styling the main menu page
    cout << "\n\t\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t\t                                     \n";
    cout << "\t\t\t\t\t                                  \n";
    cout << "\t\t\t\t\t       SUPERMARKET MAIN MENU         \n";
    cout << "\t\t\t\t\t                                   \n";
    cout << "\t\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t\t                                     \n";
    cout << "\t\t\t\t\t      |    [1] ADMIN    |\n";
    cout << "\t\t\t\t\t      |                 |\n";
    cout << "\t\t\t\t\t      |    [2] CUSTOMER |\n";
    cout << "\t\t\t\t\t      |                 |\n";
    cout << "\t\t\t\t\t      |    [3] EXIT     |\n";
    cout << "\t\t\t\t\t                                      \n";
    cout << "\n\t\t\t\tPlease select an option: ";
    cin >> choice;
    cout<<"\n";
    switch(choice)
    {
    case 1:
        cout<<"\t\t\t\t" << "___________________________________________________\n";
        cout<<"\n";
        cout <<"\t\t\t\t"<< "\t\t\t  Login Page\n";
        cout<<"\t\t\t\t" << "___________________________________________________\n";
        cout << "\n\t\t\tusername: ";
        cin >> username;
        cout << "\n\t\t\tPassword: ";
        cin >> password;

        if (username=="admin" && password=="password"){
            returnToMainMenu = shop1.admin(); // Store the return value from admin() in the variable
        }
        else
        {
            cerr<<"\t\t\tInvalid email/password"<<endl;
        }
        break;
    case 2:
        returnToMainMenu = shop1_customer.bmenu(); // Store the return value from bmenu() in the variable
        break;
    case 3:
        cout<<"\t\t\t\tThanks for shopping with us"<<endl;
        exit(0);
        break;
    default:
        cout<<"Please select from the given options";
        goto main_menu;
    }

    if (shop1.admin()) {
        system("cls");
        goto main_menu; // Go back to the main menu if the return value is true
    }

    return 0;
}
