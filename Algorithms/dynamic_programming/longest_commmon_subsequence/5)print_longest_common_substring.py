def print_lcstring(A, B):
    x, y = len(A), len(B)
    dp = [[0 for _ in range(y + 1)] for _ in range(x + 1)]
    max_length = 0
    end_index = 0

    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > max_length:
                    max_length = dp[i][j]
                    end_index = i

    substring = A[end_index - max_length : end_index]
    return substring


def print_lpstring(s):
    n = len(s)
    dp = [[False for _ in range(n)] for _ in range(n)]

    ans = ""
    for g in range(n):
        for j in range(g, n):
            i = j - g
            if g == 0:
                dp[i][j] = True
            elif g == 1:
                if s[i] == s[j]:
                    dp[i][j] = True
                else:
                    dp[i][j] = False
            else:
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                else:
                    dp[i][j] = False

            if dp[i][j]:
                ans = s[i : j + 1]

    return ans


A = "abcdxyz"
B = "xyzabcd"
print(print_lcstring(A, B))
print(print_lpstring("babad"))
