import numpy as np


# max no.of ways
def coin_exchange(coins, target):
    n = len(coins)
    dp = -np.ones((n + 1, target + 1), dtype=int)
    for i in range(n + 1):
        for j in range(target + 1):
            if i == 0:
                dp[i][j] = 0
            if j == 0:
                dp[i][j] = 1

    for i in range(1, n + 1):
        for j in range(1, target + 1):
            if coins[i - 1] <= j:
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][target]
