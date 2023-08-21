#include<iostream>
using namespace std;

void fun(int x)
{
    if(x > 0)
    {
        cout << x << " ";
        fun(x - 1);
    }
}

int main()
{
    system("cls");
    fun(5);
    
    return 0;
}