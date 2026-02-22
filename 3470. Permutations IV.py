class Solution:
    def permute(self, n: int, k: int) -> List[int]:
        fac = [1]
        for i in range(1, n+1):
            fac.append(fac[-1] * i)
            if fac[i] >= 10**15:
                fac[i] = inf

        even = n // 2
        odd = n - even
        if fac[even] * fac[odd] * (2 if even==odd else 1) < k:
            return []

        ans = []
        vis = [False] * (n+1)
        acc = 1
        if odd == even:
            prev = -1
        else:
            prev = int(odd < even)
        
        for _ in range(n):
            for i in range(1, n+1):
                if vis[i] or (i%2 == prev):
                    continue
                cur = fac[odd - int(i%2==1)] * fac[even - int(i%2==0)]
                if acc + cur > k:
                    ans.append(i)
                    vis[i] = True
                    prev = i % 2
                    if i%2 == 0:
                        even -= 1
                    else:
                        odd -= 1
                    break
                else:
                    acc += cur
    
        return ans
