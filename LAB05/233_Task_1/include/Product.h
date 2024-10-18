#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product
{
    public:
        Product();
        Product(string name, string catName, string desc,
                 int amount, float price, float rate);
        ~Product();

        string GetproductName() { return productName; }
        void SetproductName(string val) { productName = val; }
        string GetcategoryName() { return categoryName; }
        void SetcategoryName(string val) { categoryName = val; }
        string GetproductDesc() { return productDesc; }
        void SetproductDesc(string val) { productDesc = val; }
        int GetproductAmount() { return productAmount; }
        void SetproductAmount(int val) { productAmount = val; }
        float GetregPrice() { return regPrice; }
        void SetregPrice(float val) { regPrice = val; }
        float GetdiscRate() { return discRate; }
        void SetdiscRate(float val) { discRate = val; }

        void purchaseProduct(int amount);
        void restockProduct(int amount);
        float calculateDiscount (int amountOfProducts) const;
        float netTotal (int amountOfProducts);

    protected:

    private:
        string productName;
        string categoryName;
        string productDesc;
        int productAmount;
        float regPrice;
        float discRate;
};

#endif // PRODUCT_H
