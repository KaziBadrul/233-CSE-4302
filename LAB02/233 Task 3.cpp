#include <iostream>

using namespace std;

struct Fraction
{
    int top;
    int bottom;
};

int main()
{
    Fraction a, b;
    char temp;

    cout << "Enter a Fraction: ";
    cin >> a.top >> temp >> a.bottom;
    cout << "Enter another Fraction: ";
    cin >> b.top >> temp >> b.bottom;

    int top, bottom;
    top = a.top * b.bottom + a.bottom * b.top;
    bottom = a.bottom * b.bottom;
    cout << "The sum is: " << top << "/" << bottom << endl;
    return 0;
}