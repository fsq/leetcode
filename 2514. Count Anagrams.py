class Solution:
    def countAnagrams(self, s: str) -> int:
        def cnt(s):
            ans = math.factorial(len(s))
            for t in Counter(s).values():
                ans //= math.factorial(t)
            return ans % (10**9 + 7)
        
        ans = 1
        for w in s.split():
            ans *= cnt(w)
        
        return ans % (10**9 + 7)
