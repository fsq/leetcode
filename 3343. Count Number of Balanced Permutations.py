M = 10**9 + 7
C = [[0]*81 for _ in range(81)]
C[0][0] = 1
for i in range(1, len(C)):
    C[i][0] = 1
    for j in range(1, len(C[0])):
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M

class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        dig_tot = 0
        cnt = [0] * 10
        for c in num:
            d = ord(c) - ord('0')
            dig_tot += d
            cnt[d] += 1
        
        if dig_tot & 1:
            return 0
        
        @cache
        def dp(d, e, o, es, os):
            if d==10:
                return 1
            
            if cnt[d]==0:
                return dp(d+1, e, o, es, os)
            
            ans = 0
            for even in range(cnt[d]+1):
                odd = cnt[d] - even
                if e-even<0 or o-odd<0 or es-even*d<0 or os-odd*d<0:
                    continue
                ans = (ans + \
                        dp(d+1, e-even, o-odd, es-even*d, os-odd*d)*C[e][even]*C[o][odd]) % M
            return ans

        num_odd = len(num) // 2
        num_even = len(num) - num_odd
        # used digits, #even slots used, #odd slots used, even_sum, odd_sum
        return dp(0, num_even, num_odd, dig_tot//2, dig_tot//2) 


