#include <iostream>
using namespace std;

class RationalNumber
{
private:
    int numerator, denominator;

public:
    void assign(int num, int den)
    {
        if (den == 0)
            cout << "You cannot assign 0 as denominator." << endl;

        else
        {
            numerator = num;
            denominator = den;
        }
    }

    float convert()
    {
        return (float)numerator / (float)denominator;
    }

    float invert()
    {
        if (numerator == 0)
            cout << "You cannot assign 0 as denominator. Inversion failed." << endl;
        else
        {
            int temp = numerator;
            numerator = denominator;
            denominator = temp;
        }
    }

    void print()
    {
        cout << "The Rational Number is: " << numerator << "/" << denominator << endl;
    }
};

int main()
{
    RationalNumber myNum;
    myNum.assign(5, 12);
    myNum.print();
    cout << "Result is: " << myNum.convert() << endl;
    myNum.invert();
    myNum.print();
    cout << "Result is: " << myNum.convert() << endl;

    // shows error
    myNum.assign(5, 0);

    // will show error once inverted
    myNum.assign(0, 5);
    myNum.print();
    cout << "Result is: " << myNum.convert() << endl;
    myNum.invert();
}