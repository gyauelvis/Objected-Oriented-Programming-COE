#include <iostream>
#include "semester_project_header.h"
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    Inventory shop1;
    shop1.addProduct();
    shop1.displayProduct();
    shop1.modifyProducts();
    shop1.addProduct();
    shop1.displayProduct();
    return 0;
}