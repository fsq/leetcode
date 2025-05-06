class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        l = ans = 0
        c = Counter()
        # substring [l,r] has c[x]<k
        for r in range(len(s)):
            c[s[r]] += 1
            while c[s[r]] == k:
                c[s[l]] -= 1
                l += 1
            ans += l
        return ans