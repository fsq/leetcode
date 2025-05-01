class Solution:
    def remainingMethods(self, n: int, k: int, edges: List[List[int]]) -> List[int]:
        e = defaultdict(list)
        for x, y in edges:
            e[x].append(y)
        
        susp = set()
        def dfs(x):
            nonlocal susp
            susp.add(x)
            for y in e[x]:
                if y not in susp:
                    dfs(y)
        dfs(k)

        for x in e:
            if x not in susp:
                for y in e[x]:
                    if y in susp:
                        return list(range(n))
        
        return [x for x in range(n) if x not in susp]