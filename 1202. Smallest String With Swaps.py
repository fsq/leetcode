class Solution:
    def smallestStringWithSwaps(self, s: str, pr: List[List[int]]) -> str:
        n, fa = len(s), [i for i in range(len(s))]
        
        def find(x: int):
            if fa[x]!=x: fa[x] = find(fa[x])
            return fa[x]
        
        for x, y in pr:
            fx, fy = find(x), find(y)
            if fx != fy:
                fa[fx] = fy
                
        cnt = dict()
        for i in range(n):
            f = find(i)
            if not f in cnt:
                cnt[f] = [0] * 26
            cnt[f][ord(s[i])-97] += 1
        
        p = collections.defaultdict(int)
        ans = ""
        for i in range(n):
            while cnt[fa[i]][p[fa[i]]]==0:
                p[fa[i]] += 1
            ans += chr(p[fa[i]] + 97)
            cnt[fa[i]][p[fa[i]]] -= 1
        
        return ans

        