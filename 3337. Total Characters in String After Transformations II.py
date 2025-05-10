class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        m = [[0]*26 for _ in range(26)]
        M = int(1e9 + 7)

        for i in range(26):
            for c in range(i+1, i+nums[i]+1):
                m[c%26][i] = 1

        def mult(a, b):
            c = [[0]*26 for _ in range(26)]
            for i in range(26):
                for j in range(26):
                    for k in range(26):
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % M
            return c
        
        def powm(t):
            if t==1:
                return m
            p = powm(t // 2)
            p = mult(p, p)
            if t & 1:
                return mult(p, m)
            else:
                return p

        mt = powm(t)
        ans = 0
        base = [0] * 26
        for c in s:
            base[ord(c)-ord('a')] += 1
        for i in range(26):
            for j in range(26):
                ans = (ans + mt[i][j] * base[j]) % M
        return ans