// Selection sort
//  k passes gives first k smallest elements

//  parameter        Best       Worst
// comparisions    -  O(n)       O(n^2)
// swaps           -  O(1)       O(n)
// time complexity -       O(n^2)

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

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k;
        for (int j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {12, 321, 54, 323, 4, 4, 23, 433, 23};
    int size = sizeof(arr) / 4;
    cout << "Given array - [";
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (i == (sizeof(arr) / 4) - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    selection_sort(arr, size);

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