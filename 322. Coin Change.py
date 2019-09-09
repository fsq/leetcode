class Solution:
    def coinChange(self, a: List[int], tar: int) -> int:
        f = [0] + [sys.maxsize] * tar
        for x in a:
            for j in range(x, tar+1):
                f[j] = min(f[j], f[j-x] + 1)
        return -1 if f[tar]==sys.maxsize else f[tar]