class Solution:
    def validSequence(self, s: str, t: str) -> List[int]:
        i, j = len(s)-1, len(t)-1
        last = [-1] * len(t)
        while i>=0 and j>=0:
            if s[i]==t[j]:
                last[j] = i
                i -= 1
                j -= 1
            else:
                i -= 1
        i, j = 0, 0
        ans = []
        used = False
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                ans.append(i)
                i += 1
                j += 1
            elif not used and (j+1==len(t) or last[j+1]>i):
                ans.append(i)
                i += 1
                j += 1
                used = True
            else:
                i += 1
        return ans if len(ans) == len(t) else []