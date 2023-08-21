#include<iostream>
using namespace std;

double powerRecursive(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else if (exponent < 0)
    {
        return 1 / powerRecursive(base, -exponent);
    }
    else
    {
        return base * powerRecursive(base, exponent - 1);
    }
}

int main()
{
    double base;
    int exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = powerRecursive(base, exponent);
    cout << base << "^" << exponent << "=" << result << endl;

    return 0;
}