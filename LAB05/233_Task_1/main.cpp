#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include "Product.h"

using namespace std;

void EditInformationByKeyboard(Product &x) {
    string name;
    getline(cin, name);
    string catName;
    cin >> catName;
    string desc;
    getline(cin, desc);
    int amount;
    cin >> amount;
    float price;
    cin >> price;
    float disc;
    cin >> disc;

    x.SetproductName(name);
    x.SetcategoryName(catName);
    x.SetproductDesc(desc);
    x.SetproductAmount(amount);
    x.SetregPrice(price);
    x.SetdiscRate(disc);
    cout << "Name: " << name << " Price: " << price << endl;
}

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

void generateRandomInformation(Product &x) {
    string name = generator(3);
    string catName = generator(1);
    string desc = generator(10);
    int amount = 1 + (rand() % 100);
    int price = 1 + (rand() % 1000);
    int disc = 0 + (rand() % 100);

    x.SetproductName(name);
    x.SetcategoryName(catName);
    x.SetproductDesc(desc);
    x.SetproductAmount(amount);
    x.SetregPrice(price);
    x.SetdiscRate(disc);

   // cout << "Name: " << name << " Price: " << price << endl;

}

void ShowAllDiscount(Product ar[]) {
    cout << "Discounts: ";
    for (int i = 0; i < 100; i++) {
        cout << ar[i].GetdiscRate();
        cout << endl;
    }
}

float grossTotal(Product ar[]) {
    float total = 0;
    int numProducts = 1 + (rand() % 100);
    for (int i = 0; i < 100; i++) {
        total += ar[i].netTotal(numProducts);
    }
    cout << "Total Price: " << total << endl;
    cout << "Are you sure you want to purchase?" << endl;
}

bool compareFunc(Product &a, Product &b) {
    return a.GetproductName() < b.GetproductName();
}

void ShowAllAlphabetically(Product ar[]) {
    sort(ar, ar + 100, compareFunc);
    for (int i = 0; i < 100; i++) {
        cout << "Name: " << ar[i].GetproductName()
        << " Price: " << ar[i].GetregPrice()
        << " Storage: " << ar[i].GetproductAmount() << endl;
    }
}

int main()
{
    Product arr[100];

    srand(time(nullptr));
    for (int i = 0; i < 100; i++) {
        generateRandomInformation(arr[i]);
    }

    ShowAllAlphabetically(arr);
    return 0;
}
