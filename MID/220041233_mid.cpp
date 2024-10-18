#include <iostream>
#include <algorithm>
using namespace std;

int SIZE = 10;

class Candy
{
private:
    string name;
    double price;
    bool hasArtificialFlavor;
    int quantity;

public:
    // Constructors (Not necessary ig)
    // Candy() {};
    // Candy(string name, double price, bool hasAF, int quantity) : name(name), price(price), hasArtificialFlavor(hasAF), quantity(quantity) {}

    //! SET
    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setHasArtificialFlavor(bool hasArtificialFlavor)
    {
        this->hasArtificialFlavor = hasArtificialFlavor;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    //! GET
    string getName()
    {
        return this->name;
    }
    double getPrice()
    {
        return this->price;
    }
    bool getHasArtificialFlavor()
    {
        return this->hasArtificialFlavor;
    }
    int getQuantity()
    {
        return this->quantity;
    }

    //! DISPLAY
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Contains Artificial Flavor: ";
        hasArtificialFlavor ? cout << "Yes" : cout << "No";
        cout << endl;
        cout << "Quantity: " << quantity << endl;
        cout << endl;
    }

    //! OVERLOAD
    bool operator<(const Candy &right) const
    {
        return price < right.price;
    }

    bool operator>(const Candy &right) const
    {
        return price > right.price;
    }

    bool operator==(const Candy &right) const
    {
        return price == right.price;
    }

    //! Calculate Total Amount
    static int calculateTotalAmount(Candy candyArr[])
    {
        int totalAmount = 0;
        for (int i = 0; i < SIZE; i++)
        {
            totalAmount += candyArr[i].quantity;
        }
        return totalAmount;
    }

    //! SORT DESC
    static void sortCandy(Candy candyArr[])
    {
        sort(candyArr, candyArr + SIZE, [](Candy &a, Candy &b)
             { return a > b; });
        // Here a > b is using the relational operator
        // otherwise we'd have to use a.price > b.price
    }
};

int main()
{
    Candy candyArr[SIZE];

    // Creating the candies randomly
    string name[] = {"Fox", "KitKat", "Mimi", "DairyMilk", "Bubbly", "Alpenliebe", "Kofiko", "KinderJoy", "CenterFresh", "CenterFruit"};
    int price[] = {100, 50, 10, 160, 170, 5, 5, 90, 2, 3};
    bool hasAF[] = {false, false, true, true, false, true, true, true, false, false};
    int quantity[] = {5, 10, 15, 20, 10, 5, 100, 20, 10, 25};

    for (int i = 0; i < SIZE; i++)
    {
        candyArr[i].setName(name[i]);
        candyArr[i].setPrice(price[i]);
        candyArr[i].setHasArtificialFlavor(hasAF[i]);
        candyArr[i].setQuantity(quantity[i]);
        // candyArr[i].display();
    }

    // Sorting the candies according to price DESC
    Candy::sortCandy(candyArr);

    // Displaying the candies
    for (int i = 0; i < SIZE; i++)
    {
        candyArr[i].display();
    }

    cout << "Total Amount of Candy: " << Candy::calculateTotalAmount(candyArr) << endl
         << endl;
}