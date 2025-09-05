class Solution:
    def constructTransformedArray(self, a: List[int]) -> List[int]:
        n = len(a)
        ret = [0] * n
        for i, x in enumerate(a):
            j = ((i + x) % n + n) % n
            ret[i] = a[j]
        return ret
