// Bubble Sort

//  parameter        Best       Worst
// comparisions    -  O(n)       O(n^2)
// swaps           -  O(1)       O(n^2)
// time complexity -       O(n^2)

//       Adaptive                Stable            Extra memory
// (already sorted order) (duplicate elements)
//          ✔                     ✔                    ✘

#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool check = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                check = true;
            }
        }
        if (!check)
            break;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1, 65, 2, 243, 57, 3, 211, 66, 652, 3, 56, 87};
    int size = sizeof(arr) / 4;
    cout << "Given array - [";
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (i == (sizeof(arr) / 4) - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    bubble_sort(arr, size);

    cout << "\tSorted array - [";
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (i == (sizeof(arr) / 4) - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl;

    return 0;
}