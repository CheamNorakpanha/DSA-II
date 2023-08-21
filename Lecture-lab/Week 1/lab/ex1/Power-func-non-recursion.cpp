#include <iostream>
using namespace std;

double powerNonRecursive(double base, int exponent)
{
    double result = 1;

    if (exponent >= 0)
    {
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
    }
    else 
    {
        for (int i = 0; i < -exponent; i++)
        {
             result /= base;
        }
    }
    return result;
}

int main()
{
    double base;
    int exponent;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = powerNonRecursive(base, exponent);
    cout << base << "^" << exponent << " = " << result << std::endl;
    
    return 0;
}
