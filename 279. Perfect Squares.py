class Solution:
    f = [0]
    
    def numSquares(self, n: int) -> int:
        l = len(self.f)
        if l < n+1:
            self.f += [sys.maxsize] * (n+1-l)
        for i in range(l, n+1):
            j = 1
            while j*j <= i:
                self.f[i] = min(self.f[i], 1 + self.f[i-j*j])
                j += 1
        
        return self.f[n]