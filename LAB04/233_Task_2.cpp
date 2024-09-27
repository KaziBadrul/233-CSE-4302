// TASK02
#include <iostream>
using namespace std;

enum BankAccountType
{
    CHECKING,
    SAVINGS
};

class BankAccount
{
private:
    string name;
    string number;
    BankAccountType type;
    float balance;
    const float minBalance;
    float interest;

    float interestValue;
    static float sourceTax;
    static int accCount;
    static int accCreated;

public:
    BankAccount(string pubName, string pubNumber, BankAccountType pubType, int pubBalance, int pubMinBalance) : minBalance(pubMinBalance)
    {
        name = pubName;
        number = pubNumber;
        type = pubType;
        balance = pubBalance;
        interest = 0.03;
        accCount++;
        accCreated++;
    }

    void setName(string pubName)
    {
        name = pubName;
    }

    void setNumber(string pubNumber)
    {
        number = pubNumber;
    }

    void setType(BankAccountType pubType)
    {
        type = pubType;
    }

    void setInterest(float pubInterest)
    {
        interest = pubInterest;
    }

    static int getCount()
    {
        return accCount;
    }

    static int getCreated()
    {
        return accCreated;
    }

    static float getSourceTax()
    {
        return sourceTax;
    }

    float getBalance() const
    {
        return balance;
    }

    void showInfo()
    {
        cout << "-----------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
        cout << "Type: ";
        cout << (type == CHECKING ? "Checking" : "Savings") << endl;
        cout << "Balance: " << balance << endl;
        cout << "-----------------------" << endl;
    }

    void showBalance()
    {
        cout << "Balance: " << balance << endl;
    }

    void deposit(int amount)
    {
        balance += amount;
    }

    void withdrawal(int amount)
    {
        if (balance - amount >= minBalance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds!" << endl;
        }
    }

    void giveInterest()
    {
        interestValue = balance * interest;
        sourceTax = 0.1 * interestValue;
        interestValue -= sourceTax;
        balance += interestValue;
    }

    ~BankAccount()
    {
        cout << "Account of Mr. " << name
             << " with account no " << number
             << " is destroyed with a balance BDT " << balance
             << endl;
        accCount--;
    }
};

int BankAccount::accCount = 0;
int BankAccount::accCreated = 0;
float BankAccount::sourceTax = 0;

void display_stat()
{
    cout << "Total Accounts Remaining: " << BankAccount::getCount() << endl;
    cout << "Total Accounts Created: " << BankAccount::getCreated() << endl;
    cout << "Source Tax: " << BankAccount::getSourceTax() << endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B)
{
    if (A.getBalance() > B.getBalance())
    {
        return A;
    }
    else
    {
        return B;
    }
}

int main()
{
    BankAccount A("Rahim", "123456", SAVINGS, 5000, 1000);
    BankAccount B("Karim", "654321", CHECKING, 10000, 2000);
    display_stat();
    cout << "BALANCE OF A: " << endl;
    A.showBalance();
    A.giveInterest();

    B.setInterest(0.05);
    B.giveInterest();

    cout << "Info OF A AND B AFTER INTEREST: " << endl;
    A.showInfo();
    B.showInfo();

    BankAccount C = Larger(A, B);

    C.showInfo();
    display_stat();
}