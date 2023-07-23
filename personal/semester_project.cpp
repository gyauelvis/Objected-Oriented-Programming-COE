#include <iostream>
#include "main.h"
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    Inventory shop1;
    Cashier shop1_customer;
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
           shop1.admin();
        }
        else
        {
            cerr<<"Invalid email/password";
        }
        break;
    case 2:
            shop1_customer.bmenu();
            if(shop1_customer.bmenu() == false){
                system("cls");
                goto main_menu;
            }
            break;
    case 3:
            cout<<"\t\tThanks for shopping with us"<<endl;
            exit(0);
            break;
    default:
            cout<<"Please select from the given options";
            goto main_menu;
    }

    return 0;
}
