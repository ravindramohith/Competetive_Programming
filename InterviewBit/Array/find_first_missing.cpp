#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(vector<int> &A)
{
    int n = A.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            if (i != j)
            {
                swap(&A[i], &A[j]);
            }
            j++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        int x = abs(A[i]);
        if (A[x - 1] >= 0)
        {
            A[x - 1] = -A[x - 1];
        }
    }
    for (int i = 0; i < j; i++)
    {
        if (A[i] > 0)
            return i + 1;
    }
    return j + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> C = {97, 0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50};
    cout << firstMissingPositive(C);
    for (auto i : C)
        cout << i << " ";

    return 0;
}