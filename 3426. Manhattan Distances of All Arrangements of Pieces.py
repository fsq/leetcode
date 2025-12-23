class Solution:
    def distanceSum(self, m: int, n: int, k: int) -> int:
        M = int(1e9 + 7)
        a = n*m - 2
        b = k - 2
        fac = [1]
        for i in range(1, a+1):
            fac.append(fac[-1] * i % M)
        inv_b = pow(fac[b], M-2, M)
        inv_a_minus_b = pow(fac[a-b], M-2, M)
        com = fac[a] * inv_b * inv_a_minus_b % M

        ans = 0
        for i in range(1, n+1):
            for j in range(1, m+1):
                f = m*(i*(i-1)//2 + (n-i)*(n-i+1)//2) + n*(j*(j-1)//2 + (m-j)*(m-j+1)//2)
                ans = (ans + f) % M

        return ans * pow(2, M-2, M) * com % M
