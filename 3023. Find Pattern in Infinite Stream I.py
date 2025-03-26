# Definition for an infinite stream.
# class InfiniteStream:
#     def next(self) -> int:
#         pass
class Solution:
    def findPattern(self, stream: Optional['InfiniteStream'], p: List[int]) -> int:
        next = [0] * len(p)
        i, j = 1, 0
        while i < len(p):
            if p[i] == p[j]:
                next[i] = j + 1
                i += 1
                j += 1
            elif j > 0:
                j = next[j-1]
            else:
                i += 1
        i, j = 0, 0
        while True:
            x = stream.next()
            while j > 0 and x != p[j]:
                j = next[j-1]
            if x == p[j]:
                j += 1
                if j == len(p):
                    return i - len(p) + 1
            i += 1
        return -1