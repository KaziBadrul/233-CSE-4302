#include "Product.h"

Product::Product()
{
    //ctor
}

Product::Product(string name, string catName, string desc,
                 int amount, float price, float rate) {
    productName = name;
    productDesc = desc;
    productAmount = amount;
    categoryName = catName;
    regPrice = price;
    discRate = rate;
                 }

Product::~Product()
{
    //dtor
}

void Product::purchaseProduct(int amount) {
    if (amount <= 0) {
        return;
    }
    if (productAmount - amount >= 0) {
        productAmount -= amount;
    }
}

void Product::restockProduct(int amount) {
    if (amount <= 0) {
        return;
    }
    productAmount += amount;
}

float Product::calculateDiscount (int amountOfProducts) const {
    if (amountOfProducts >= 5) {
        if (amountOfProducts >= 10) {
            return regPrice * (discRate + 3)/100;
        }
        return regPrice * (discRate)/100;
    }
    else return 0;
}

float Product::netTotal (int amountOfProducts) {
    // purchaseProduct(amountOfProducts);
    return regPrice + calculateDiscount(amountOfProducts);
}
