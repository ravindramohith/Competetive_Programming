#include <bits/stdc++.h>
using namespace std;

long bitwise(long a, long b, long c, long d)
{
    long long n = d;
    long long dp[4];
    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    for (int i = 3; i <= n; i++)
    {
        dp[3] = (dp[2] | dp[1]) ^ (dp[0]);
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
    }
    return dp[3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long result1 = bitwise(100000000, 10000000, 100000000, 10000);
    cout << "Result 1: " << result1 << endl;
    return 0;
}
