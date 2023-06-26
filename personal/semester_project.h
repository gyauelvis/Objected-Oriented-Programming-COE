

class Inventory
{
    // private:
    // public:
};

// Let us first discuss the properties of a cash register. The register has some cash
// on hand, it accepts the amount from the customer, and if the amount deposited
// is more than the cost of the item, then—if possible—it returns the change. For
// simplicity, we assume that the user deposits the money greater than or equal to
// the cost of the product. The cash register should also be able to show to the juice
// machine’s owner the amount of money in the register

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
