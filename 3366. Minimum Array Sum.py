class Solution:
    def minArraySum(self, a: List[int], k: int, op1: int, op2: int) -> int:
        n = len(a)
        f = [[inf]*(n+1) for _ in range(n+1)]
        f[0][0] = 0
        for i, x in enumerate(a):
            for p in reversed(range(min(i+1, op1)+1)):
                for q in reversed(range(min(i+1, op2)+1)):
                    f[p][q] += x
                    if p > 0:
                        f[p][q] = min(f[p][q], f[p-1][q] + (x+1)//2)
                        if q > 0 and (x+1)//2 >= k:
                            f[p][q] = min(f[p][q], f[p-1][q-1] + (x+1)//2 - k)
                    if q > 0 and x >=k:
                        f[p][q] = min(f[p][q], f[p][q-1] + x - k)
                        if p > 0:
                            f[p][q] = min(f[p][q], f[p-1][q-1] + (x-k+1)//2)
        
        return min([min(b) for b in f])
