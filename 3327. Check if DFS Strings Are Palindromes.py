class Solution:
    def findAnswer(self, pa: List[int], st: str) -> List[bool]:
        # https://cp-algorithms.com/string/manacher.html
        def manacher_odd(s: str):
            n, l, r = len(s), 0, 1
            s = '$' + s + '^'
            p = [0] * (n+2)
            for i in range(1, n+1):
                p[i] = min(r-i, p[l+r-i]);
                while s[i+p[i]] == s[i-p[i]]:
                    p[i] += 1
                if i+p[i] > r:
                    l, r = i-p[i], i+p[i]
            return p[1:-1]
        
        def manacher(s: str):
            p = manacher_odd('#' + ('#'.join(s)) + '#')
            odd, even = [], []
            for i in range(len(s)):
                even.append((p[i*2]-1) // 2)
                odd.append(p[i*2+1] // 2)
            return odd, even
        
        n = len(pa)
        e = defaultdict(list)
        l = [0] * n
        r = [0] * n
        for i in range(1, n):
            e[pa[i]].append(i)

        s = []
        def dfs(x):
            l[x] = len(s)
            for y in sorted(e[x]):
                dfs(y)
            s.append(st[x])
            r[x] = len(s) - 1
        dfs(0)

        odd, even = manacher(s)
        ans = []
        for x in range(n):
            mid = (r[x]+l[x]+1) // 2
            if (r[x]-l[x]+1) & 1:
                ans.append(odd[mid] + mid > r[x])
            else:
                ans.append(even[mid] + mid > r[x])
        return ans
