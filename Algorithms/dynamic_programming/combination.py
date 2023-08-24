def combination(n, r):
    dp = [[0 for _ in range(r + 1)] for _ in range(n + 1)]
    MOD = 1e9
    for i in range(n + 1):
        for j in range(r + 1):
            if i == j or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD


print(combination(9, 2))
# l = [1,2,3,1,2]
# ans = 0
# for i in l:
#     ans = ans ^ i
# print(ans)
