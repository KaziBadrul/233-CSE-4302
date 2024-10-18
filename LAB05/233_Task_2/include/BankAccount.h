#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;

enum Status
{
    Low,
    Moderate,
    High
};

class BankAccount
{
    public:
        BankAccount();
        BankAccount(string pName, string pDOB, int pSalary, int pJoiningYear);
        ~BankAccount();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string GetdateOfBirth() { return dateOfBirth; }
        void SetdateOfBirth(string val) { dateOfBirth = val; }
        int GetbaseSalary() { return baseSalary; }
        void SetbaseSalary(int val) { baseSalary = val; }
        int GetjoiningYear() { return joiningYear; }
        void SetjoiningYear(int val) { joiningYear = val; }
        float calculateTotalSalary();
        Status getStatus();
        float calculateBonus();

    protected:

    private:
        string name;
        string dateOfBirth;
        int baseSalary;
        int joiningYear;
};

#endif // BANKACCOUNT_H
