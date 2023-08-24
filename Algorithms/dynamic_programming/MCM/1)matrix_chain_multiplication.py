def MCM_rec(arr, i, j):
    if i >= j:
        return 0

    ans = 1e9
    for k in range(i, j):
        ans = min(
            arr[i - 1] * arr[k] * arr[j] + MCM_rec(arr, i, k) + MCM_rec(arr, k + 1, j),
            ans,
        )

    return ans


def MCM(arr):
    n = len(arr)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(1, n):
        dp[i][i] = 0

    # L->Chain length
    #[......,i(subarray with length L-1),.....]
    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            dp[i][j] = 1e9
            for k in range(i, j):
                dp[i][j] = min(
                    dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j], dp[i][j]
                )


    return dp[1][n-1]

# print(MCM_rec(arr, 1,n-1))
