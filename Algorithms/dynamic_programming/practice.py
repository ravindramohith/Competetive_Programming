def knapsack(wts, val, W, n):
    dp = [[0 for i in range(W + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if wts[i] <= j:
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wts[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][W]


def lcs(A, B):
    x, y = len(A), len(B)
    dp = [[0 for i in range(y + 1)] for i in range(x + 1)]
    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[x][y]


def MCM():
    pass
