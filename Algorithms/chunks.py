class Solution:
    @staticmethod
    def upload(chunks):
        res = []
        if not chunks:
            return res

        chunkTree = sorted(chunks, key=lambda x: x[0])

        for i in range(len(chunks)):
            currChunk = chunks[i]
            overlapDone = False

            j = 0
            while j < len(chunkTree):
                chunk = chunkTree[j]

                if overlapDone and not Solution.overlaps(currChunk, chunk):
                    break

                if Solution.overlaps(currChunk, chunk):
                    overlapDone = True
                    currChunk = Solution.merge(currChunk, chunk)
                    del chunkTree[j]
                    j -= 1
                j += 1

            chunkTree.append(currChunk)
            chunkTree.sort(key=lambda x: x[0])

            res.append(chunkTree.copy())

        return res

    @staticmethod
    def overlaps(a, b):
        return (
            max(a[0], b[0]) <= min(a[1], b[1]) or a[1] + 1 == b[0] or b[1] + 1 == a[0]
        )

    @staticmethod
    def merge(a, b):
        start = min(a[0], b[0])
        end = max(a[1], b[1])
        return [start, end]


# # Test cases
# print(Solution.upload([[1, 1], [2, 2], [3, 3]]))
# print(Solution.upload([[7, 9], [1, 3], [8, 15], [6, 9], [2, 4]]))
# print(Solution.upload([[1, 3], [8, 15], [6, 9], [2, 5], [1, 9]]))


def solve(chunks):
    def compute_overlap(a, b):
        a1, a2 = a
        b1, b2 = b

        start = max(a1, b1)
        end = min(a2, b2)

        if start <= end:
            return [start, end]
        else:
            return None  # No overlap

    def reduce_intervals(a, b):
        a1, a2 = a
        b1, b2 = b

        start = max(a1, b1)
        end = min(a2, b2)

        if start <= end:
            return [start, end]
        else:
            return [a, b]

    chunk_arr = [chunks[0]]
    res = [chunks[0][1] - chunks[0][0]]
    for chunk in chunks[1:]:
        for c in chunk_arr:
            r = compute_overlap(c, chunk)
            if r:
                r=


solve([[7, 9], [1, 3], [8, 15], [6, 9], [2, 4]])
# for chunk in chunks:
