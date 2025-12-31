class Solution:
    # O(50n) prefix sum
    # for t,i,j => max ft[i,j]+tot_k-fk[i,j]
    def maxFrequency1(self, a: List[int], k: int) -> int:
        n = len(a)
        f = []
        for x in a:
            f.append((1 if x==k else 0) + (f[-1] if f else 0))
        ans = tot_k = f[-1]
        
        for t in range(1, 51):
            mn = ft = 0
            for i in range(n):
                if a[i] == t:
                    ft += 1
                si = ft - f[i]
                ans = max(ans, si-mn+tot_k)
                mn = min(mn, si)
        return ans
    
    # O(50n) dp
    # t=>1, k=>-1, calculate max subarray sum
    # O(n): ft[i,j]-fk[i,j]=(ft[i,j]+fk[0,j])-fk[0,i], dp get max ft[i,j]+fk[0,j]
    def maxFrequency(self, a: List[int], k: int) -> int:
        ans = tot_k = a.count(k)
        for t in range(1, 51):
            if t == k:
                continue
            dp = res = 0
            for x in a:
                if x == t:
                    dp += 1
                elif x == k:
                    dp -= 1
                if dp < 0:
                    dp = 0
                res = max(res, dp)
            ans = max(ans, res+tot_k)
        return ans
