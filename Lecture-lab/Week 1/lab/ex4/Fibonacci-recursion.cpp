#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int num;

    cout << "Enter the number of Fibonacci terms to generate: ";
    cin >> num;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < num; i++)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}

// int rFibNum(int a, int b, int n)
// {
//     if(n == 1)
//     {
//         return a;
//     }
//     else if(n == 2)
//     {
//         return b;
//     }
//     else
//     {
//         return rFibNum(a, b, n-1) + rFibNum(a, b, n-2);
//     }
// }

// int main()
// {
//     int a, b, n;

//     cout << rFibNum(2,3,4) << endl;
// }