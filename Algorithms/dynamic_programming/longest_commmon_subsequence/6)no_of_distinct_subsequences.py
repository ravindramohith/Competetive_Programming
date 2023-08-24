def num_of_subsequnces(s, t):
    """
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    ra_b_bbit
    rab_b_bit
    rabb_b_it
    """
    x, y = len(s), len(t)
    dp = [[0 for i in range(y + 1)] for i in range(x + 1)]

    for i in range(x + 1):
        dp[i][0] = 1
    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[x][y]
