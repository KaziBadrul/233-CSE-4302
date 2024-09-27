// TASK03
#include <iostream>
using namespace std;

enum Status
{
    Low,
    Moderate,
    High
};

class Employee
{
private:
    string EmpName;
    int ID;
    float BaseSalary;
    float TotalSalaryForExperience;
    int JoiningYear;
    int Age;
    float calculateTotalSalary();
    float calculateBonus();
    Status getStatus();

public:
    void FeedInfo(string name, int id, float salary, int year, int age)
    {
        EmpName = name;
        ID = id;
        BaseSalary = salary;
        JoiningYear = year;
        Age = age;
        TotalSalaryForExperience = calculateTotalSalary();
    }

    void ShowInfo()
    {
        cout << "Name: " << EmpName << endl;
        cout << "ID: " << ID << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Status: ";
        cout << (getStatus() == Low ? "Low" : (getStatus() == Moderate ? "Moderate" : "High"))
             << endl;
        cout << "Bonus: " << calculateBonus() << endl;
        cout << "Total Salary: " << TotalSalaryForExperience + calculateBonus() << endl;
    }
};

float Employee::calculateTotalSalary()
{
    int year = 2024 - JoiningYear;
    cout << "YEAR: " << year << endl;
    float salary = 0;

    for (int i = 0; i < year; i++)
    {
        // cout << "Year " << i << "of year " << year << endl;
        BaseSalary = BaseSalary + 0.03 * BaseSalary;
        // cout << "BASE SALARY IS NOW: " << BaseSalary << endl;
    }
    salary = BaseSalary;
    salary += BaseSalary * 0.1 + BaseSalary * 0.03 + BaseSalary * 0.05;
    return salary;
}

Status Employee::getStatus()
{
    float salary = TotalSalaryForExperience;
    if (Age <= 25)
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

float Employee::calculateBonus()
{
    if (getStatus() == Low)
    {
        return BaseSalary * 0.05;
    }
    else if (getStatus() == Moderate)
    {
        return BaseSalary * 0.1;
    }
    else
    {
        return BaseSalary * 0.15;
    }
}

int main()
{
    Employee emp;
    emp.FeedInfo("Adrit", 123, 50000, 2018, 22);
    emp.ShowInfo();
}