class Solution:
    def maxSubstringLength(self, s: str, k: int) -> bool:
        p = {}
        for i, c in enumerate(s):
            if c in p:
                p[c][1] = i
            else:
                p[c] = [i, i]

        includes = defaultdict(set)
        for c, (l, r) in p.items():
            for i in range(l, r+1):
                if s[i] != c:
                    includes[c].add(s[i])
        
        def dfs(i, vis):
            vis.add(i)
            ret = p[i]
            for j in includes[i]:
                if j in vis:
                    continue
                l, r = dfs(j, vis)
                ret[0] = min(ret[0], l)
                ret[1] = max(ret[1], r)
            return ret
        
        a = sorted([dfs(i, set()) for i in p.keys()])
        f = [0] * len(a)
        for i, (l, r) in enumerate(a):
            if not (l==0 and r==len(s)-1):
                f[i] = 1
            for j, (l1, r1) in enumerate(a[:i]):
                if r1 < l:
                    f[i] = max(f[i], f[j] + 1)

        return max(f) >= k

