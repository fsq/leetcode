class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = ans = 0
        cnt = {}
        for i,x in enumerate(s):
            if x in cnt:
                cnt[x] += 1
            else:
                cnt[x] = 1
            while cnt[x] > 1:
                cnt[s[l]] -= 1
                l += 1
            ans = max(ans, i-l+1)
        return ans