#include <iostream>
using namespace std;

class Temperature
{
private:
    float temperature;
    float incrementVal;

public:
    void setIncrementStep(float n)
    {
        incrementVal = n;
    }

    float getTemperature()
    {
        return temperature;
    }

    void increment()
    {
        temperature += incrementVal;
    }

    void resetTemperature()
    {
        temperature = 0;
    }
};

int main()
{
    Temperature temp;

    // temp is 0
    temp.resetTemperature();
    cout << "Temperature is: " << temp.getTemperature() << endl;

    // incremented by 5.2 two times
    temp.setIncrementStep(5.2);
    temp.increment();
    temp.increment();
    cout << "Temperature is: " << temp.getTemperature() << endl;
}