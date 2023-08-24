def lcs_recursive(x, y, A, B, dp):
    if x == 0 or y == 0:
        return 0

    if dp[x][y] != -1:
        return dp[x][y]
    if A[x - 1] == B[y - 1]:
        dp[x][y] = 1 + lcs_recursive(x - 1, y - 1, A, B, dp)
    else:
        dp[x][y] = max(
            lcs_recursive(x, y - 1, A, B, dp), lcs_recursive(x - 1, y, A, B, dp)
        )

    return dp[x][y]


def lcs(A, B):
    x = len(A)
    y = len(B)
    dp = [[-1 for i in range(y + 1)] for i in range(x + 1)]
    return lcs_recursive(x, y, A, B, dp)


def lcs_topdown(A, B):
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

    return dp[x][y]


def lcs_topdown_improved(A, B):
    x, y = len(A), len(B)
    dp = [[0 for i in range(y + 1)] for i in range(x + 1)]

    for i in range(1, x + 1):
        for j in range(1, y + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[x][y]


lcs_topdown_improved("rabbbit", "rabbit")


def longest_palindromic_subsequence(A):
    return lcs_topdown_improved(A, A[::-1])


def shortest_common_supersequence(A, B):
    return len(A) + len(B) - lcs_topdown_improved(A, B)


def min_no_of_insertions_and_deletions_A_to_B(A, B):
    insertions, deletions = len(A) - lcs_topdown_improved(A, B), len(
        B
    ) - lcs_topdown_improved(A, B)
    return insertions + deletions


def min_no_of_deletions_to_palindrome(A):
    return len(A) - longest_palindromic_subsequence(A)


def min_no_of_insertions_to_palindrome(A):
    return shortest_common_supersequence(A, A[::-1]) - len(A)


def longest_repeating_subsequence(A):
    def lrs_topdown(A, B):
        x, y = len(A), len(B)
        dp = [[-1 for i in range(y + 1)] for i in range(x + 1)]

        for i in range(x + 1):
            for j in range(y + 1):
                if i == 0 or j == 0:
                    dp[i][j] = 0

        for i in range(1, x + 1):
            for j in range(1, y + 1):
                if A[i - 1] == B[j - 1] and i != j:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[x][y]

    return lrs_topdown(A, A)


def sequence_pattern_match(subseq, seq):
    """Return boolean if subseq is a sub sequnce of seq or not"""
    return len(subseq) == lcs_topdown_improved(subseq, seq)


def wordBreak(s: str, wordDict) -> bool:
    dp = dict()
    m = set(wordDict)

    def solve(s):
        if not s:
            return True
        if s in dp:
            return dp[s]

        for i in range(len(s)):
            r = s[: i + 1]
            if r in m:
                if solve(s[i + 1 :]):
                    dp[s] = True
                    return True
        dp[s] = False
        return False

    return solve(s)

