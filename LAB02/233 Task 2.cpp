#include <iostream>
using namespace std;

enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

int main()
{
    char input;
    cout << "Enter employee type (First letter only)\nlaborer, secretary, manager, accountant, executive, researcher):  ";
    cin >> input;

    etype x;

    switch (input)
    {
    case 'l':
        x = laborer;
        break;
    case 's':
        x = secretary;
        break;
    case 'm':
        x = manager;
        break;
    case 'a':
        x = accountant;
        break;
    case 'e':
        x = executive;
        break;
    case 'r':
        x = researcher;
        break;
    }

    switch (x)
    {
    case laborer:
        cout << "Employee type: laborer" << endl;
        break;
    case secretary:
        cout << "Employee type: secretary" << endl;
        break;
    case manager:
        cout << "Employee type: manager" << endl;
        break;
    case accountant:
        cout << "Employee type: accountant" << endl;
        break;
    case executive:
        cout << "Employee type: executive" << endl;
        break;
    case researcher:
        cout << "Employee type: researcher" << endl;
        break;
    }

    return 0;
}