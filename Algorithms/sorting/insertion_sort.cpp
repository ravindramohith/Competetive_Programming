// Insertion Sort

//  parameter        Best       Worst
// comparisions    -  O(n)       O(n^2)
// swaps           -  O(1)       O(n^2)
// time complexity -       O(n^2)

//       Adaptive                Stable            Extra memory
// (already sorted order) (duplicate elements)
//          ✔                     ✔                    ✘

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = i - 1, x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {2, 53, 432, 5, 645, 2, 345, 4, 56, 43, 5, 342};
    int size = sizeof(arr) / 4;
    cout << "Given array - [";
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (i == (sizeof(arr) / 4) - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    insertion_sort(arr, size);

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