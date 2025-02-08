class Solution:

    def dfs(e: List[List[int]], x: int, pre=-1) -> (int, int):
        m1 = m2 = 0
        ans = 1
        for y in e[x]:
            if y != pre:
                ly, ay = Solution.dfs(e, y, x)
                if ly >= m1:
                    m2 = m1
                    m1 = ly
                elif ly > m2:
                    m2 = ly
                ans = max(ans, ay)

        ans = max(ans, m1+m2+1)
        return m1+1, ans
    
    def LongestPath(edges: List[List[int]]):
        n = len(edges) + 1
        e = [[] for i in range(n)]
        for pr in edges:
            e[pr[0]].append(pr[1])
            e[pr[1]].append(pr[0])
        return Solution.dfs(e, 0)[1]


    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        l1 = Solution.LongestPath(edges1)
        l2 = Solution.LongestPath(edges2)
        return max(l1-1, l2-1, l1//2 + l2//2 + 1)