#include <bits/stdc++.h>
using namespace std;

int knapsack_recursive(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack_recursive(wt, val, W - wt[n - 1], n - 1, dp), knapsack_recursive(wt, val, W, n - 1, dp));
    }
    else
    {
        return dp[n][W] = knapsack_recursive(wt, val, W, n - 1, dp);
    }
}

int knapsack_recursive_memorization(vector<int> &wt, vector<int> &val, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    knapsack_recursive(wt, val, W, n, dp);
    return dp[n][W];
}

int knapsack_topdown(vector<int> &wt, vector<int> &val, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}