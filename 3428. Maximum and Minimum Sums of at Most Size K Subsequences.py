M = int(1e9 + 7)
f = [[0] * (70+1) for _ in range(100000+1)]
f[0][0] = 1
for i in range(100001):
    f[i][0] = 1
    for j in range(1, 71):
        f[i][j] = (f[i-1][j] + f[i-1][j-1]) % M
    
class Solution:
    def minMaxSums(self, a: List[int], k: int) -> int:
        a.sort()
        n = len(a)

        # or calculate weight w[i] = (2*w[i-1]-comb(i,k))
        ans = sum(a) * 2 % M
        for l in range(2, k+1):
            for i in range(n):
                if n-i-1 >= l-1:
                    ans = (ans + a[i]*f[n-i-1][l-1]) % M
                if i >= l-1:
                    ans = (ans + a[i]*f[i][l-1]) % M
        return ans
