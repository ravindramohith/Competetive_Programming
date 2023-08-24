#include <bits/stdc++.h>
using namespace std;

int subset_sum_count(vector<int> &arr, int sum)
{
    int n = arr.size();
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
    return dp[n][sum];
}

int main()
{
    return 0;
}