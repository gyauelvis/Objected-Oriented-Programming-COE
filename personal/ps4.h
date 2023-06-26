// Pointers and Objects


// The name of the class is stockType.
class stockType
{

    // The class stockType has the following instance variables: name of type string, symbol of type string; currentPrice, lowPriceOfTheDay, highPriceOfTheDay,previousDayClosingPrice, fiftyTwoWeeksHigh, and fiftyTwoWeeksLow are of type double.
    string name, symbol;
    double currentPrice, lowPriceOfTheDay, highPriceOfTheDay, previousDayClosingPrice, fiftyTwoWeeksHigh, fiftyTwoWeeksLow;

public:
    // print — outputs the data stored in the member variables with the appropriate titles
    void print() const;
    // setStockName—function to set the stock name

}

// getName—value-returning function to return the stock name
// setSymbol—function to set the stock symbol
// getSymbol—value-returning function to return the stock symbol
// setCurrentPrice—function to set the current price of the stock
// getCurrentPrice—value-returning function to return stock,s current
// price
// setLowPriceOfTheDay—function to set stock,s lowest price of the day
// getLowPriceOfTheDay—value-returning function to return stock's
// lowest price of the day
// setHighPriceOfTheDay—function to set the stock,s highest price of
// the day
// getHighPriceOfTheDay—value-returning function to return stock's
// highest price of the day
// setPreviousDayClosingPrice—function to set the stock,s previous day closing price
// getPreviousDayClosingPrice—value-returning function to return
// stock,s closing price of the previous day
// setFiftyTwoWeeksHigh—function to set the stock,s fifty two
// weeks highest price
// 734 | Chapter 10: Classes and Data Abstraction
// getFiftyTwoWeeksHigh—value-returning function to return
// stock,s fifty two weeks highest price
// setFiftyTwoWeeksLow—function to set the stock,s fifty two
// weeks lowest price
// getFiftyTwoWeeksLow—value-returning function to return stock,s
// fifty two weeks lowest price
// percentGainLoss—value returning function to determine the
// percentage gain or loss between the current price and previous
// day closing price.
// constructor—with default parameters: The default value of name
// and symbol is the empty string "", and the default value of remaining instance variables is 0
