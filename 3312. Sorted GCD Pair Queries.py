class Solution:
    def gcdValues(self, a: List[int], queries: List[int]) -> List[int]:
        cnt = Counter(a)
        mx = max(a)
        g = [0] * (mx + 1)
        for i in reversed(range(1, len(g))):
            # tot: #elements multiple of i, >=i
            # sub: #pairs with gcd=2i, 3i...
            tot, sub = 0, 0
            for k in range(i, len(g), i):
                tot += cnt[k]
                if k > i:
                    sub += g[k]
            g[i] = tot*(tot-1)//2 - sub
        
        for i in range(1, len(g)):
            g[i] += g[i-1]
        ans = []
        for q in queries:
            ans.append(bisect_left(g, q + 1))
        return ans
                