def no_of_ways_to_evaluate_boolean_expression_to_True(exp):
    n = len(exp)
    dp = [[[-1 for i in range(2)] for i in range(n)] for i in range(n)]

    def no_of_ways_to_evaluate_boolean_expression_to_True_rec(expression, i, j, target):
        if i >= j:
            dp[i][j][target] = 1 if (expression[i] == "T") == target else 0
            return dp[i][j][target]

        if dp[i][j][target] != -1:
            return dp[i][j][target]

        ways = 0
        for k in range(i + 1, j, 2):
            if dp[i][k - 1][True] == -1:
                dp[i][j][
                    True
                ] = leftTrue = no_of_ways_to_evaluate_boolean_expression_to_True_rec(
                    expression, i, k - 1, True
                )
            else:
                leftTrue = dp[i][k - 1][True]

            if dp[i][k - 1][False] == -1:
                dp[i][k - 1][
                    False
                ] = leftFalse = no_of_ways_to_evaluate_boolean_expression_to_True_rec(
                    expression, i, k - 1, False
                )
            else:
                leftFalse = dp[i][k - 1][False]

            if dp[k + 1][j][True] == -1:
                dp[k + 1][j][
                    True
                ] = rightTrue = no_of_ways_to_evaluate_boolean_expression_to_True_rec(
                    expression, k + 1, j, True
                )
            else:
                rightTrue = dp[k + 1][j][True]

            if dp[k + 1][j][False] == -1:
                dp[k + 1][j][
                    False
                ] = rightFalse = no_of_ways_to_evaluate_boolean_expression_to_True_rec(
                    expression, k + 1, j, False
                )
            else:
                rightFalse = dp[k + 1][j][False]

            if expression[k] == "&":
                ways = ways + (
                    leftTrue * rightTrue
                    if target
                    else (
                        (leftFalse * rightFalse)
                        + (leftFalse * rightTrue)
                        + (leftTrue * rightFalse)
                    )
                )
            elif expression[k] == "|":
                ways = ways + (
                    leftFalse * rightFalse
                    if not target
                    else (
                        (leftTrue * rightTrue)
                        + (leftFalse * rightTrue)
                        + (leftTrue * rightFalse)
                    )
                )
            elif expression[k] == "^":
                ways = ways + (
                    (leftFalse * rightTrue) + (leftTrue * rightFalse)
                    if target
                    else ((leftFalse * rightFalse) + (leftTrue * rightTrue))
                )

        dp[i][j][target] = ways
        return ways

    return no_of_ways_to_evaluate_boolean_expression_to_True_rec(exp, 0, n - 1, True)


expr = "T^T^T^F|F&F^F|T^F^T"
print(no_of_ways_to_evaluate_boolean_expression_to_True(expr))
