#include <iostream>
using namespace std;

int reverseNumberNonRecursive(int number)
{
    int reversedNumber = 0;

    while (number != 0)
    {
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10;
    }
    return reversedNumber;
}

int main()
{
    int number = 379;
    int reversedNumber = reverseNumberNonRecursive(number);
    cout << "Original Number: " << number << endl;
    cout << "Reversed Number (Non-Recursive): " << reversedNumber << endl;
    return 0;
}
