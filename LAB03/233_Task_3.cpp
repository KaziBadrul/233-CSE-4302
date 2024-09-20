#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNum;
    string accountTypeVal;
    float balanceVal = 0;

public:
    void customerDetails(string nameParam, int accNumParam)
    {
        name = nameParam;
        accountNum = accNumParam;
    }

    void accountType(string typeParam)
    {
        if (typeParam == "current" || typeParam == "Current")
        {
            accountTypeVal = "Current";
        }
        else if (typeParam == "saving" || typeParam == "Saving")
        {
            accountTypeVal = "Saving";
        }
        else
        {
            cout << "Invalid Account Type." << endl;
        }
    }

    void balance()
    {
        cout << "Balance: " << balanceVal << endl;
    }

    void deposit(float dep)
    {
        balanceVal += dep;
        cout << "Deposited: " << dep << endl;
        cout << "Total Balance: " << balanceVal << endl;
    }

    void withdraw(float wdraw)
    {
        if (wdraw > balanceVal)
        {
            cout << "You don't have sufficient balance." << endl;
            return;
        }
        balanceVal -= wdraw;
        cout << "Withdrawn: " << wdraw << endl;
        cout << "Total Balance: " << balanceVal << endl;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNum << endl;
        cout << "Account Type: " << accountTypeVal << endl;
        cout << "Balance: " << balanceVal << endl;
    }
};

int main()
{
    BankAccount myAccount;
    myAccount.customerDetails("Kazi Badrul", 220041233);
    myAccount.accountType("current");
    myAccount.deposit(5000);
    myAccount.balance();
    myAccount.withdraw(2000.50);
    myAccount.balance();

    // shows error because not sufficient balance
    myAccount.withdraw(10000);
    myAccount.display();
}