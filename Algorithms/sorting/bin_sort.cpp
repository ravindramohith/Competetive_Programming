// Bin sort

// time complexity -       O(n)

//       Adaptive                Stable            Extra memory
// (already sorted order) (duplicate elements)
//          ✘                     ✔                    ✔

#include <bits/stdc++.h>
using namespace std;

int find_max(int arr[], int n)
{
    int max = -1e9;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Linked List node
class Node
{
public:
    int value;
    Node *next;
};

void insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
    { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int remove(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void bin_sort(int arr[], int n)
{
    int max = find_max(arr, n);

    // Create bins array
    Node **bins = new Node *[max + 1];

    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on arr values
    for (int i = 0; i < n; i++)
    {
        insert(bins, arr[i]);
    }

    // Update arr with sorted elements
    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            arr[j++] = remove(bins, i);
        }
        i++;
    }

    // remove heap memory
    delete[] bins;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {2, 6, 7, 5, 8, 12, 3, 10, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array - [";
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        if (i == (sizeof(arr) / 4) - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    bin_sort(arr, n);

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