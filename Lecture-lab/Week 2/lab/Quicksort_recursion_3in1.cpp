#include<iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int first_ind, int last_ind, int pivot)
{
    // low = first_ind, high = last_ind
    int i = first_ind;
    int j = first_ind;

    while (i <= last_ind)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return j - 1;
}

void quickSort(int arr[], int first_ind, int last_ind)
{
    if (first_ind < last_ind)
    {
        int pivot = arr[last_ind];
        int pos = partition(arr, first_ind, last_ind, pivot);

        quickSort(arr, first_ind, pos - 1);
        quickSort(arr, pos + 1, last_ind);
    }
}

int main()
{
    int arr[] = {5, 8, 2, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
