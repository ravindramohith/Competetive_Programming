#include <bits/stdc++.h>
using namespace std;

int lessthan_nums(vector<int> &V, int num)
{
    int low = 0, high = V.size() - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (V[mid] < num)
        {
            ans = mid + 1;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int findMedian(vector<vector<int>> &A)
{
    int low = 1, high = INT_MAX, n = (A.size()) * (A[0].size());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int nums_lessthan_mid = 0;
        for (int row = 0; row < A.size(); row++)
        {
            nums_lessthan_mid += lessthan_nums(A[row], mid);
        }
        if (nums_lessthan_mid > n / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> A = {{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};

    vector<int> B = {1, 2, 3, 4, 6, 6, 7, 8, 9};

    return 0;
}