#include <bits/stdc++.h>
using namespace std;

int target_sum(vector<int> &arr, int target)
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

    int count = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (target == sum - 2 * i)
        {
            count = v[i];
            break;
        }
    }

    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}