#include <iostream>
using namespace std;

// Constant time function
int constant_time_function(int x)
{
    return x + 1;
}

// Logarithmic time function
int logarithmic_time_function(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return logarithmic_time_function(x / 2) + 1;
    }
}

// Linear time function
int linear_time_function(int x)
{
    int sum = 0;

    for (int i = 0; i < x; i++)
    {
        sum += i;
    }
    return sum;
}

// Quadratic time function
int quadratic_time_function(int x)
{
    int sum = 0;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
        sum += i * j;
        }
    }
    return sum;
}

// Linear time function with m
int linear_time_function_with_m(int x, int m)
{
    int sum = 0;

    for (int i = 0; i < x; i++)
    {
        sum += i * m;
    }
    return sum;
}

int main()
{
    int x = 100;
    int m = 10;

    cout << "=> O(1): " << constant_time_function(x) << endl;
    cout << "=> O(log n): " << logarithmic_time_function(x) << endl;
    cout << "=> O(n): " << linear_time_function(x) << endl;
    cout << "=> O(n^2): " <<quadratic_time_function(x) << endl;
    cout << "=> O(n + m): " << linear_time_function_with_m(x, m) <<
    endl;

    return 0;
}

// Output:
// => O(1): 101
// => O(log n): 7
// => O(n): 4950
// => O(n^2): 24502500
// => O(n + m): 49500