// Count sort

// time complexity -       O(n)

//       Adaptive                Stable            Extra memory
// (already sorted order) (duplicate elements)
//          ✘                     ✔                    ✔

#include <bits/stdc++.h>
using namespace std;

int find_max(int *arr, int n)
{
    int max = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void count_sort(int *arr, int n)
{
    int max = find_max(arr, n), *count;
    count = (int *)malloc(sizeof(int) * (max + 1));

    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int i = 0, j = 0;
    while (j < max + 1)
    {
        if (count[j] > 0)
        {
            arr[i++] = j;
            count[j]--;
        }
        else
            j++;
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
    count_sort(arr, size);

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