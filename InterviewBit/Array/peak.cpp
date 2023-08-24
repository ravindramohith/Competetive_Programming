#include <bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A)
{
    vector<int> minIndices(0), maxIndices(0);
    int max = A[0], min = A[A.size() - 1];

    // finding max
    for (int i = 1; i < A.size(); i++)
    {
        if (max < A[i])
        {
            max = A[i];
            maxIndices.push_back(i);
        }
    }
    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (min > A[i])
        {
            min = A[i];
            minIndices.push_back(i);
        }
    }

    for (auto const &i : minIndices)
    {
        for (auto const &j : maxIndices)
        {
            if (i == j)
                return 1;
        }
    }

    return 0;

    // for (auto i : maxIndices)
    //     cout << i << " ";
    // for (auto i : minIndices)
    //     cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {5, 1, 4, 4};

    cout << perfectPeak(A) << endl;

    return 0;
}