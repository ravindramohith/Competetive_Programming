#include <bits/stdc++.h>
using namespace std;

int min_diff_subsets_count(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    // main code
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] += dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] += dp[i - 1][j];
        }
    }

    vector<int> v = dp[n];

    // traversing through midway and getting the min of (sum-2s1)
    int min_diff = INT_MAX;
    int min_diff_subsets = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (v[i])
        {
            min_diff = sum - 2 * i;
            min_diff_subsets = v[i];
            break;
        }
    }

    return min_diff_subsets;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}