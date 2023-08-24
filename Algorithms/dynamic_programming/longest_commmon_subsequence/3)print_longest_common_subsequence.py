def print_lcs(A, B):
    x, y = len(A), len(B)
    dp = [[-1 for i in range(y + 1)] for i in range(x + 1)]

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

    i, j = x, y
    string = ""
    while i > 0 and j > 0:
        if A[i - 1] == B[j - 1]:
            string += A[i - 1]
            i -= 1
            j -= 1

        else:
            if dp[i - 1][j] > dp[i][j - 1]:
                i -= 1
            else:
                j -= 1

    print(string[::-1])


def print_scs(A, B):
    x, y = len(A), len(B)
    dp = [[-1 for i in range(y + 1)] for i in range(x + 1)]

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

    i, j = x, y
    string = ""
    while i > 0 and j > 0:
        if A[i - 1] == B[j - 1]:
            string += A[i - 1]
            i -= 1
            j -= 1

        else:
            if dp[i - 1][j] > dp[i][j - 1]:
                string += A[i - 1]
                i -= 1
            else:
                string += B[j - 1]
                j -= 1

    print(string[::-1])


def print_lps(A):
    print_lcs(A, A[::-1])


print_lcs("abcdef", "abcefg")
print_scs("abcdef", "abcefg")
print_lps("aacabdkacaa")
