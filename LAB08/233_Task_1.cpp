#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string name) : name(name) {};
    virtual void display()
    {
        cout << "Name: " << name << endl;
    };
};

class Employee : public Person
{
private:
    int employeeID;

protected:
    float salary;

public:
    Employee(string name, int employeeID, float salary) : Person(name), employeeID(employeeID), salary(salary) {};

    void display()
    {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    };
};

class Intern : public Employee
{
private:
    string schoolName;

public:
    Intern(string name, int employeeID, float salary, string schoolName) : Employee(name, employeeID, salary), schoolName(schoolName) {};

    void display()
    {
        Employee::display();
        cout << "School Name: " << schoolName << endl;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    Manager(string name, int employeeID, float salary, string department) : Employee(name, employeeID, salary), department(department) {};

    void display()
    {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

class Director : public Manager
{
private:
    float bonus;

public:
    Director(string name, int employeeID, float salary, string department, float bonus) : Manager(name, employeeID, salary, department), bonus(bonus) {};

    void display()
    {
        Manager::display();
        cout << "Bonus: " << bonus << endl;
    }
};

int main()
{
    // Person a("Adrit");
    // a.display();

    // Employee b("Ariq", 101, 3000);
    // b.display();

    // Intern c("Mahin", 102, 500, "Little Willie");
    // c.display();

    // Manager d("Fattah", 100, 150000, "HR");
    // d.display();

    Director e("Badrul", 200, 250000, "Marketing", 50000);
    e.display();
};
