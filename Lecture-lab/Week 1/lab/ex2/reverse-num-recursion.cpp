#include<iostream>
using namespace std;

int reverseNumRecursion(int number, int reversedNumber = 0)
{
    if(number == 0)
    {
        return reversedNumber;
    }
    else
    {
        return reverseNumRecursion(number / 10, reversedNumber * 10 + number % 10);
    }
}

int main()
{
    int number = 379;
    int reversedNumber = reverseNumRecursion(number);

    cout << "Original Number: " << number << endl;
    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}