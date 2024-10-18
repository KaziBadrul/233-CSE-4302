#include "BankAccount.h"
#include <string>
using namespace std;

BankAccount::BankAccount()
{
    //ctor
}

BankAccount::BankAccount(string pName, string pDOB, int pSalary, int pJoiningYear)
{
    if (pName.length() <= 2) {
        pName = "John Doe";
    }
    name = pName;

    dateOfBirth = pDOB;

    if (pSalary < 10000 || pSalary > 100000) {
        pSalary = 10000;
    }
    baseSalary = pSalary;
    joiningYear = pJoiningYear;
}

BankAccount::~BankAccount()
{
    //dtor
}

float BankAccount::calculateTotalSalary()
{
    int year = 2024 - joiningYear;
    // cout << "YEAR: " << year << endl;
    float salary = baseSalary;

    for (int i = 0; i < year; i++)
    {
        // cout << "Year " << i << "of year " << year << endl;
        salary = salary + 0.03 * salary;
        // cout << "BASE SALARY IS NOW: " << baseSalary << endl;
    }
    salary += salary * 0.1 + salary * 0.03 + salary * 0.05;
    return salary;
}

Status BankAccount::getStatus()
{
    float salary = calculateTotalSalary();
    int age = 2024 - stoi(dateOfBirth);
    if (age <= 25)
    {
        if (salary <= 20000)
        {
            return Low;
        }
        else
            return Moderate;
    }
    else
    {
        if (salary <= 21000)
        {
            return Low;
        }
        else if (salary > 21000 && salary <= 60000)
        {
            return Moderate;
        }
        else
            return High;
    }
}

float BankAccount::calculateBonus()
{
    if (getStatus() == Low)
    {
        return baseSalary * 0.05;
    }
    else if (getStatus() == Moderate)
    {
        return baseSalary * 0.1;
    }
    else
    {
        return baseSalary * 0.15;
    }
}
