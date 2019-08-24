class Solution:
    def findAnagrams(self, s: str, t: str) -> List[int]:
        n, m = len(s), len(t)
        if m > n:
            return []
        d, cnt = dict(), dict()
        for c in t:
            cnt[c] = cnt.get(c, 0) + 1
        for i in range(m-1):
            d[s[i]] = d.get(s[i], 0) + 1
        ans = []
        for i in range(n-m+1):
            if i > 0: 
                d[s[i-1]] -= 1
                if d[s[i-1]]==0:
                    del d[s[i-1]]
            d[s[i+m-1]] = d.get(s[i+m-1], 0) + 1
            if cnt == d:
                ans.append(i)
        return ans