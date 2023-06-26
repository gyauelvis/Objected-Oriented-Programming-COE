#include <iostream>
#include <string>
#include "semester_project_headerFile.h"

// The default amount in totalCash will be 500 and Cash In will be 0 if not otherwise specified by the owner of the shop
Cashier::Cashier() : totalCash(500),
                     cashIn(0){};
Cashier::Cashier(double totalAmount, double amountcashIn) : totalCash(totalAmount), cashIn(amountcashIn){};
Cashier::Cashier(double totalAmount) : totalCash(totalAmount), cashIn(0){};
