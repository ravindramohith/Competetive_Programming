import numpy as np
def LCS(A, B):
    x, y = len(A), len(B)
    dp = -np.ones((x + 1, y + 1), dtype=int)

    for i in range(x + 1):
        for j in range(y + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0

    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[x][y]


def shortest_subsequence(A, B):
    x, y = len(A), len(B)
    return x + y - LCS(A, B)

