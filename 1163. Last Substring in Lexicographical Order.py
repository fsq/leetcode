class Solution:
    def lastSubstring(self, s: str) -> str:
        mx = max(s)
        p = [i for i,c in enumerate(s) if c==mx]
        ans = p[-1]
        for i in reversed(range(len(p)-1)):
            x, y = p[i], ans
            while x<ans and y<len(s) and s[x]==s[y]:
                x, y = x+1, y+1
            if x==ans or y==len(s) or s[x]>s[y]:
                ans = p[i]
        return s[ans:]