import numpy as np


def unbounded_knapsack(wt, val, W, n):
    dp = -np.ones((n + 1, W + 1), dtype=int)
            

    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            if wt[i - 1] <= j:
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][W]
