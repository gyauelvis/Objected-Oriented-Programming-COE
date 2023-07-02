// In this example, we design and implement a class to manipulate an integer. Consider the integer 6203851479017652638. Some of the operations that can be performed on this integer are: count the number of even digits, odd digits, and zeros; find the sum  of the digits; reverse the digits; split the number into blocks of three-digit numbers; and  find the sum of these numbers. The following class defines some of these operations

class integerManipulation
{
private:
    long long int number, revNum;
    int evenCount, oddCount, zeroCount;

public:
    // Member function declaration

    // Default constructor
    integerManipulation();
    // Constructor with parameters
    integerManipulation(long long int);
    int coutEvenNumbers();
    int coutOddNumbers();
    int coutZeroes();
    int sumOfDigits();
    int reverseDigits();
    void splitNumberInto3DigitNumbsAndSumThem() const;
};

// Member function definition
integerManipulation::integerManipulation() : number(0), revNum(0), evenCount(0), oddCount(0), zeroCount(0){};
integerManipulation::integerManipulation(long long int numb) : number(numb), revNum(0), evenCount(0), oddCount(0), zeroCount(0){};

int integerManipulation::coutEvenNumbers()
{
}

// int interManipulation::reverseDigits(){
    
// };
