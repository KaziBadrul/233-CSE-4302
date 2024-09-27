// TASK01
#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    string unqID;
    float unitPrice;
    int initialQuantity;
    int maxAmount;
    static float totalInventoryValue;

public:
    Product(string pubName, string pubUnqID, float pubUnitPrice, int pubInitialQuantity, int pubMaxAmount)
    {
        name = pubName;
        unqID = pubUnqID;
        unitPrice = pubUnitPrice;
        initialQuantity = pubInitialQuantity;
        maxAmount = pubMaxAmount;

        totalInventoryValue += initialQuantity * unitPrice;
        cout << "INITIAL TOTAL: " << totalInventoryValue << endl;
    }

    void addToInventory(int addedQuantity)
    {
        if (addedQuantity > 0 && initialQuantity < maxAmount)
        {
            totalInventoryValue -= initialQuantity * unitPrice;
            if (initialQuantity + addedQuantity > maxAmount)
            {
                initialQuantity = maxAmount;
            }
            else
            {
                initialQuantity += addedQuantity;
            }
            totalInventoryValue += initialQuantity * unitPrice;
        }
    }

    bool isAvailable()
    {
        if (initialQuantity > 0)
        {
            return true;
        }
        return false;
    }

    void purchase(int purchasedQuantity)
    {
        if (purchasedQuantity <= 0)
            return;
        totalInventoryValue -= initialQuantity * unitPrice;
        if (purchasedQuantity <= initialQuantity)
        {
            initialQuantity -= purchasedQuantity;
        }
        totalInventoryValue += initialQuantity * unitPrice;
    }

    void updatePrice(float discountPercent)
    {
        if (discountPercent > 100 || discountPercent <= 0)
            return;
        totalInventoryValue -= initialQuantity * unitPrice;
        unitPrice = unitPrice - (discountPercent * unitPrice) / 100;
        totalInventoryValue += initialQuantity * unitPrice;
    }

    void displayInventoryValue()
    {
        cout << "Inventory Value: " << initialQuantity * unitPrice << endl;
    }

    void displayDetails()
    {
        cout << "-------------------------------" << endl;
        cout << "Product ID: " << unqID << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << unitPrice << endl;
        cout << "Quantity: " << initialQuantity << endl;
        if (isAvailable())
            cout << "In Stock!" << endl;
        else
            cout << "Not in Stock." << endl;
        cout << "-------------------------------" << endl;
    }

    void displayTotalInventoryValue()
    {
        cout << "Total Inventory Value: " << totalInventoryValue << endl;
    }
};

float Product::totalInventoryValue = 0;

// Create 2 more products and display the total inventory value of all 3 products.
int main()
{
    Product p1 = Product("Apple", "220041219", 100, 50, 300);
    p1.addToInventory(50);
    p1.purchase(50);
    p1.updatePrice(5);
    p1.displayInventoryValue();
    p1.displayDetails();

    Product p2 = Product("Orange", "220041220", 15.25, 25, 250);
    Product p3 = Product("Banana", "220041221", 65.50, 195, 450);

    p1.displayTotalInventoryValue();
}