import numpy as np


def rod_cutting(L, lengths, prices, n):
    dp = -np.ones((n + 1, L + 1), dtype=int)

    for i in range(n + 1):
        for j in range(L + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0

    for i in range(1, n + 1):
        for j in range(1, L + 1):
            if lengths[i - 1] <= j:
                dp[i][j] = max(dp[i - 1][j], prices[i - 1] + dp[i][j - lengths[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][L]