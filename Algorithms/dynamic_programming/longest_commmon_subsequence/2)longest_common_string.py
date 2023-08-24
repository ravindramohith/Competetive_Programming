def longest_common_substring(A, B):
    x, y = len(A), len(B)
    dp = [[-1 for i in range(y + 1)] for i in range(x + 1)]

    for i in range(x + 1):
        for j in range(y + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0

    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] != B[j - 1]:
                dp[i][j] = 0
            else:
                dp[i][j] = 1 + dp[i - 1][j - 1]

    return dp[x][y]