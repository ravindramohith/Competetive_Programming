#include <bits/stdc++.h>
using namespace std;

int min_subset_diff(vector<int> &arr)
{
    int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);

    // performing subset sum array for last row of dp array which contains booleans for arr of size n whether they had a subset of sum j(column numbers)
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    // main code
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // getting the last row
    vector<bool> v = dp[n];

    // traversing through midway and getting the min of (sum-2s1)
    int min_diff = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (v[i])
        {
            min_diff = sum - 2 * i;
            break;
        }
    }

    return min_diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}