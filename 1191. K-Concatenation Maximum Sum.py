class Solution:
    def kConcatenationMaxSum(self, a: List[int], k: int) -> int:
        s, ans, tot = 0, 0, 0
        for x in a:
            s = max(x, s + x)
            ans = max(ans, s)
            tot += x
        
        if k==1: return ans
        l = list(itertools.accumulate(a))
        r = reversed(list(itertools.accumulate(a[::-1])))
        f = max(0, max(l)) + max(0, max(r))
       
        return max(ans, f + (k-2)*max(tot, 0)) % int(1e9+7)