class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        anc = defaultdict(lambda: -1)
        e = defaultdict(list)
        ne = defaultdict(list)
        for i in range(1, len(parent)):
            e[parent[i]].append(i)
        ans = [0] * len(s)
        
        def dfs(x):
            prev = anc[s[x]]
            ans[x] += 1
            if prev != -1:
                parent[x] = prev

            anc[s[x]] = x
            for y in e[x]:
                dfs(y)

            if parent[x] != -1:
                ans[parent[x]] += ans[x]

            anc[s[x]] = prev

        dfs(0)

        return ans