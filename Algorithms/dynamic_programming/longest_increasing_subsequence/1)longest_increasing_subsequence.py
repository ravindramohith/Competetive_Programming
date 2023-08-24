def longest_increasing_subsequence(nums):
    n = len(nums)
    dp = [1 for i in range(n)]
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], 1 + dp[j])

    return max(dp)


def num_of_longest_increasing_subsequence(nums):
    n = len(nums)
    dp = [1 for i in range(n)]
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], 1 + dp[j])

    lis = max(dp)
    num_dp = [0 for i in range(lis)]
    while lis > 1:
        indices = [i for i, val in enumerate(dp) if val == lis - 1]
        # for i in indices:
            # num_dp[i-1]
        # lis -= 1



print(num_of_longest_increasing_subsequence([10, 10, 22, 9, 33, 21, 50, 41, 60, 80, 1]))
