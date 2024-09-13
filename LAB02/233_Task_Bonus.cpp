#include <iostream>
#include <vector>
using namespace std;

struct Car
{
    int id;
    string brand;
    string model;
    int year;
    string fuelType;
    int milage;
    bool efficiency;
    int price;
};

void printCar(Car car)
{
    cout << "Car: " << car.id << endl;
    cout << "Brand: " << car.brand << endl;
    cout << "Year: " << car.year << endl;
    cout << "Fuel Type: " << car.fuelType << endl;
    cout << "Mileage: " << car.milage << " km/l" << endl;
}

void fuelEfficiency(Car car)
{
    if (car.milage >= 15)
        cout << "This car is fuel efficient.";
    else
        cout << "This car is not fuel efficient.";
}

float fuelConsumption(Car car)
{
    return 100.00 / car.milage;
}

float fuelCost(Car car)
{
    float consumed = fuelConsumption(car);
    if (car.fuelType == "Petrol")
    {
        return consumed * 0.89;
    }
    if (car.fuelType == "Diesel")
    {
        return consumed * 3.24;
    }
    if (car.fuelType == "Hybrid")
    {
        return consumed * 2.45;
    }
}

int main()
{
    int n;
    cout << "Number of cars: ";
    cin >> n;

    vector<Car> cars;
    Car car;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cout << "****************************\n";
        cout << "Car " << i + 1 << ": \n";
        car.id = i + 1;
        cout << "Brand: ";
        // cin >> car.brand;
        getline(cin, car.brand);
        cout << "Model: ";
        getline(cin, car.model);
        cout << "Year: ";
        cin >> car.year;
        cout << "Fuel Type: ";
        cin >> car.fuelType;
        cout << "Milage(km/l): ";
        cin >> temp;
        car.milage = stoi(temp);
        cars.push_back(car);
        cin.clear();
        cin.ignore();
        cout << "__________________________" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        car = cars[i];
        printCar(car);
        fuelEfficiency(car);
        cout << "Estimated cost for 100km: $" << fuelCost(car);
        cout << endl;
    }
}