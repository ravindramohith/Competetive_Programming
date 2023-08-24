// Quick Sort

//  parameter        Best       Worst
// comparisions    -  O(n)       O(n^2)
// swaps           -  O(1)       O(n)
// time complexity -  O(nlogn)   O(n^2)

//       Adaptive                Stable            Extra memory
// (already sorted order) (duplicate elements)
//          ✘                     ✘                    ✘

#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start, j = end;
    do
    {
        do
            i++;
        while (arr[i] <= pivot);

        do
            j--;
        while (arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);

    } while (i < j);

    swap(&arr[start], &arr[j]);
    return j;
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int j = partition(arr, start, end);
        quick_sort(arr, start, j);
        quick_sort(arr, j + 1, end);
    }
}

int main()
{
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = sizeof(arr) / 4;
    cout << "Given array - [";
    for (int i = 0; i < n; i++)
    {
        if (i == (n)-1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    quick_sort(arr, 0, n);

    cout << "\tSorted array - [";
    for (int i = 0; i < n; i++)
    {
        if (i == (n)-1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl;
    return 0;
}