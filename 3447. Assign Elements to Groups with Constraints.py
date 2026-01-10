class Solution:
    def assignElements(self, groups: List[int], elements: List[int]) -> List[int]:
        ans = defaultdict()
        mx = max(groups)
        ans = [inf] * (mx + 1)
        vis = set()
        for i, x in enumerate(elements):
            if x in vis:
                continue
            vis.add(x)
            for y in range(x, mx+1, x):
                ans[y] = min(ans[y], i)
        return [ans[g] if ans[g]!=inf else -1 for g in groups]
