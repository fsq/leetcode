class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        e = defaultdict(list)
        for [a, b], v in zip(equations, values):
            e[a].append([b, v])
            e[b].append([a, 1/v])

        def dfs(vis, x, target, val):
            vis.add(x)
            if x == target:
                return True, val
            for y, ratio in e[x]:
                if not y in vis:
                    found, v = dfs(vis, y, target, val * ratio)
                    if found:
                        return True, v
            return False, -1
        
        ans = []
        for a, b in queries:
            if (a not in e) or (b not in e):
                ans.append(-1)
            else: 
                vis = set()
                ans.append(dfs(vis, a, b, 1)[1])
        return ans