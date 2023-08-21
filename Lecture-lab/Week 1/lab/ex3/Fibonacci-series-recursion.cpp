#include <iostream>
using namespace std;

// Function to calculate and print Fibonacci series
// Non-return Function
void printFibonacci(int n, int a = 0, int b = 1)
{
    if (n > 0)
    {
        cout << a << " ";

        // Recursive call with updated values
        printFibonacci(n - 1, b, a + b);
    }
}

int main()
{
    int n = 6;

    cout << "Fibonacci Series: ";
    printFibonacci(n);

    return 0;
}
