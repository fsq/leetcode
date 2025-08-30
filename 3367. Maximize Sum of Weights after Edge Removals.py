class Solution:
    def maximizeSumOfWeights(self, edges: List[List[int]], k: int) -> int:
        e = defaultdict(list)
        for u, v, w in edges:
            e[u].append([v, w])
            e[v].append([u, w])

        def dp(x, fa):
            df = []
            ans = 0
            for y, w in e[x]:
                if y != fa:
                    yes, no = dp(y,x)
                    if yes+w > no:
                        df.append(yes+w - no)
                    ans += no

            df = nlargest(k, df)
            ans += sum(df)
            return ans-(df[-1] if len(df)==k else 0), ans

        return max(dp(0, -1))
