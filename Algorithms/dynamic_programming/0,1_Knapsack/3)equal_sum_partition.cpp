#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> &arr, int sum)
{
    int n = arr.size();
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
    return dp[n][sum];
}

bool equal_sum_partition(vector<int> &arr, int sum)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 2)
        return false;

    return subset_sum(arr, sum/2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}