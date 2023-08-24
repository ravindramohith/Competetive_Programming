# def scramble_string_rec(a, b):
#     if a == b:
#         return True

#     if len(a) <= 1:
#         return False

#     n, scrambled = len(a), False
#     for i in range(1, n):
#         swapped = scramble_string_rec(a[:i], b[n - i :]) and scramble_string_rec(
#             a[i:], b[: n - i]
#         )
#         non_swapped = scramble_string_rec(a[:i], b[:i]) and scramble_string_rec(
#             a[i:], b[i:]
#         )
#         if swapped or non_swapped:
#             scrambled = True
#             break
#     return scrambled


def scramble_string(a, b):
    if len(a) != len(b):
        return False
    
    map = dict()

    def scramble_string_rec(a, b):
        if not a or not b:
            return False
        if a + "_" + b in map:
            return map[a + "_" + b]

        if a == b:
            map[a + "_" + b] = True
            return True

        n, scrambled = len(a), False
        for i in range(1, n):
            if a[:i] + "_" + b[n - i :] in map:
                swapped1 = map[a[:i] + "_" + b[n - i :]]
            else:
                swapped1 = map[a[:i] + "_" + b[n - i :]] = scramble_string_rec(
                    a[:i], b[n - i :]
                )

            if a[i:] + "_" + b[: n - i] in map:
                swapped2 = map[a[i:] + "_" + b[: n - i]]
            else:
                swapped2 = map[a[i:] + "_" + b[: n - i]] = scramble_string_rec(
                    a[i:], b[: n - i]
                )

            if a[:i] + "_" + b[:i] in map:
                non_swapped1 = map[a[:i] + "_" + b[:i]]
            else:
                non_swapped1 = map[a[:i] + "_" + b[:i]] = scramble_string_rec(
                    a[:i], b[:i]
                )

            if a[i:] + "_" + b[i:] in map:
                non_swapped2 = map[a[i:] + "_" + b[i:]]
            else:
                non_swapped2 = map[a[i:] + "_" + b[i:]] = scramble_string_rec(
                    a[i:], b[i:]
                )

            if (swapped1 and swapped2) or (non_swapped1 and non_swapped2):
                scrambled = True
                break

        return scrambled

    return scramble_string_rec(a, b)


print(scramble_string("si", "iw"))
