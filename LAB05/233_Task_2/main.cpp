#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "BankAccount.h"

using namespace std;

string generator(int wordCount) {
	int range = 3 + (rand() % 5);
    string name = "";
    for (int i = 0; i < wordCount; i++) {
            for (int j = 0; j < range; j++) {
                char nameChar = 65 + (rand() % 25);
                name += nameChar;
            }
            name += " ";
        }
    return name;
}

void setInfo(BankAccount &x, string name, string DOB, int baseSalary, int joiningYear) {
    x.Setname(name);
    x.SetdateOfBirth(DOB);
    x.SetbaseSalary(baseSalary);
cout << "BASE SALARY SET: " << baseSalary << endl;
    x.SetjoiningYear(joiningYear);
}

void generateRandomInformation(BankAccount &x) {
    string name = generator(2);
    string DOB = to_string(3 + (rand() % 5));
    //string baseSalary = generator(10);
    //int amount = 1 + (rand() % 100);
    int baseSalary = 1 + (rand() % 1000);

    int joiningYear = 2000 + (rand() % 20);

    setInfo(x, name, DOB, baseSalary, joiningYear);

   // cout << "Name: " << name << " Price: " << price << endl;

}


void getInfo(BankAccount &x) {
    cout << x.Getname() << endl;
    cout <<x.GetdateOfBirth()<< endl;
    cout <<x.GetbaseSalary()<< endl;
    // cout << "BASE SALARY GET: " << x.GetbaseSalary() << endl;
    cout <<x.GetjoiningYear()<< endl;
}

bool compareFunc(BankAccount &a, BankAccount &b) {
    return a.calculateTotalSalary() < b.calculateTotalSalary();
}

void ShowAllBasedOnTotalSalary(BankAccount x[]) {
    sort(x, x + 100, compareFunc);
}

int main()
{
    BankAccount arr[100];

    srand(time(nullptr));
    for (int i = 0; i < 100; i++) {
        generateRandomInformation(arr[i]);
    }
    ShowAllBasedOnTotalSalary(arr);
    for (int i = 0; i < 100; i++) {
        getInfo(arr[i]);
    }
    return 0;
}
