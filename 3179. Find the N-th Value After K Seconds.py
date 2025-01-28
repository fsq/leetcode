class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        M = int(1e9 + 7)
        a = [1] * n
        for _ in range(k):
            for i in range(1, n):
                a[i] = (a[i-1] + a[i]) % M
        return a[n-1]