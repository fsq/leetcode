class Solution:
    def maximumValueSum(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        rows = [nlargest(3, [(a[i][j], i, j) for j in range(m)]) for i in range(n)]
        cols = [nlargest(3, [(a[i][j], i, j) for i in range(n)]) for j in range(m)]
        # List[List[()]] -> List[()]
        st = nlargest(11, set(chain(*rows)).intersection(set(chain(*cols))))
        ans = -math.inf
        for cb in combinations(st, 3):
            if len(set([a[1] for a in cb]))==3 and len(set([a[2] for a in cb]))==3:
                ans = max(ans, sum([a[0] for a in cb]))
        return ans