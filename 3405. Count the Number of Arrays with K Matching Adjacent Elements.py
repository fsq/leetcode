M = int(1e9 + 7)

f = [1] + [0] * 100000
g = [1] + [0] * 100000
for i in range(1, 100001):
    f[i] = f[i-1] * i % M
    # a/b % M = a * b^(M-2) % M
    g[i] = pow(f[i], M-2, M)

def comb(x, y):
    return f[x] * g[y] * g[x-y] % M

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return comb(n-1, k) * m * pow(m-1, n-k-1, M) % M
