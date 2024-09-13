#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    char temp;

    cout << "Enter a Fraction: ";
    cin >> a >> temp >> b;
    cout << "Enter another Fraction: ";
    cin >> c >> temp >> d;

    int top, bottom;
    top = a * d + b * c;
    bottom = b * d;
    cout << "The sum is: " << top << "/" << bottom << endl;
    return 0;
}