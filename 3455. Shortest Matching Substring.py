class Solution:
    def shortestMatchingSubstring(self, s: str, t: str) -> int:
        t = [s for s in t.split('*') if s]
        n = len(s)

        def get_nxt(s):
            nxt = [0] * len(s)
            i, j = 1, 0
            while i < len(s):
                if s[i] == s[j]:
                    nxt[i] = j + 1
                    i += 1
                    j += 1
                elif j > 0:
                    j = nxt[j-1]
                else:
                    i += 1
            return nxt

        def kmp(t):
            ans = [0] * n + [-1]
            nxt = get_nxt(t)
            i = j = 0
            while i < len(s):
                if s[i] == t[j]:
                    i += 1
                    j += 1
                    if j == len(t):
                        ans[i-j] = 1
                        j = nxt[j-1]
                elif j > 0:
                    j = nxt[j-1]
                else:
                    i += 1
            return ans

        ps = [kmp(seg) for seg in t]
        for p in ps:
            for i in reversed(range(0, len(p))):
                if p[i] == 1:
                    p[i] = i
                else:
                    p[i] = p[i+1] if i+1<len(p) else -1
        
        ans = inf
        for i in range(len(s)):
            j = i
            for p, s in zip(ps, t):
                j = p[j]
                if j == -1:
                    break
                j += len(s)
            if j != -1:
                ans = min(ans, j - i)
        
        return -1 if ans == inf else ans
