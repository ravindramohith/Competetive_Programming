import numpy as np


# min number of coins
def min_coin_exchange(coins, target):
    n = len(coins)
    dp = -np.ones((n + 1, target + 1), dtype=int)
    for i in range(n + 1):
        for j in range(target + 1):
            if j == 0:
                dp[i][j] = 0
            if i == 0:
                dp[i][j] = 1e9 - 1
            elif i == 1:
                if j % coins[0] == 0:
                    dp[i][j] = j / coins[0]
                else:
                    dp[i][j] = 1e9 - 1

    for i in range(1, n + 1):
        for j in range(1, target + 1):
            if coins[i] <= j:
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][target]
