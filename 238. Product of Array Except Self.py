class Solution:
    def productExceptSelf(self, a: List[int]) -> List[int]:
        if len(a)<=1: return a
        f = a.copy()
        for i in reversed(range(len(a)-1)):
            f[i] *= f[i+1]
        f[0] = f[1]
        for i in range(1, len(a)-1):
            f[i] = a[i-1] * f[i+1]
            a[i] *= a[i-1]
        f[-1] = a[-2]
        return f
            