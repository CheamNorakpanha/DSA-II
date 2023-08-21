#include <iostream>
using namespace std;

// Slow solution
int slow_sol(int n)
{
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            sum += j;
        }
    }
    return sum;
}

// Fast solution
int fast_sol(int n)
{
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{

    // Output the result of slow solution
    cout << "The slow solution: " << slow_sol(20) << endl;

    // Output the result of fast solution
    cout << "The fast solution: " << fast_sol(20) << endl;

    return 0;
}

// Output:
// The slow solution: 1540
// The fast solution: 210