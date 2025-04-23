class Solution:
    def validSubstringCount(self, s: str, t: str) -> int:
        target = Counter(t)
        cur = defaultdict(int)
        l = r = fit = ans = 0
        while l < len(s):
            while r < len(s) and fit < len(target):
                cur[s[r]] += 1
                if cur[s[r]] == target[s[r]]:
                    fit += 1
                r += 1
            if fit == len(target):
                ans += len(s) - r + 1
            if cur[s[l]] == target[s[l]]:
                fit -= 1
            cur[s[l]] -= 1
            l += 1
        return ans
            
