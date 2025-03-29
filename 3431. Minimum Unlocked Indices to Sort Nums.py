class Solution:
    def minUnlockedIndices(self, a: List[int], locked: List[int]) -> int:
        def rangeIndex(a, x):
            try:
                first = a.index(x)
            except:
                return len(a), 0
            last = len(a) - a[::-1].index(x) - 1
            return first, last
        first1, last1 = rangeIndex(a, 1)
        first2, last2 = rangeIndex(a, 2)
        first3, last3 = rangeIndex(a, 3)
        if last1 > first3:
            return -1
        return sum(locked[first2:last1]) + sum(locked[first3:last2])