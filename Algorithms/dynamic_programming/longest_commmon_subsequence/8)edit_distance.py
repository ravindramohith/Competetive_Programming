def edit_distance(A, B):
    """
    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
    """

    x, y = len(A), len(B)
    dp = [[0 for i in range(y + 1)] for i in range(x + 1)]

    for i in range(x + 1):
        for j in range(y + 1):
            if i == 0 and j == 0:
                continue
            if i == 0:
                dp[i][j] = dp[i][j - 1] + 1
            if j == 0:
                dp[i][j] = dp[i - 1][j] + 1

    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1], 1 + dp[i - 1][j - 1])

    return dp[x][y]
