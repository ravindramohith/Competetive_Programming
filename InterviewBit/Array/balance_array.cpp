#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    vector<int> V(A.size());
    for (int i = A.size() - 1; i >= 0; i--)
    {
        V[i] = A[i];
        if (i + 2 < A.size())
            V[i] += V[i + 2];
    }
    for (int i = 0; i < A.size(); i++)
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {5, 5, 2, 5, 8};
    solve(A);

    return 0;
}