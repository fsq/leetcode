class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        c = [[0]*26]
        c[0][ord(s[0])-97] += 1
        for i in range(1, len(s)):
            nxt = c[-1][:]
            nxt[ord(s[i])-97] += 1
            c.append(nxt)
        ans = [k>=sum([(c[r][i]-(0 if l==0 else c[l-1][i])) & 1 for i in range(26)])//2 
               for l,r,k in queries]
        return ans