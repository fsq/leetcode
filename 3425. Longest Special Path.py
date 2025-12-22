class Solution:
    def longestSpecialPath(self, edges: List[List[int]], a: List[int]) -> List[int]:
        n = len(a)
        e = [[] for _ in range(n)]
        for x,y,w in edges:
            e[x].append((y, w))
            e[y].append((x, w))
        
        pref = [0]
        vis = defaultdict(int)
        ans = 0
        l = 1
        def dfs(x, level=1, p=0, tot_w=0, pre=-1):
            nonlocal ans, l

            pref.append(tot_w)
            prev_x = vis[a[x]]
            p = max(p, prev_x)
            vis[a[x]] = level

            path_w = pref[-1] - pref[p+1]
            if path_w > ans or (path_w==ans and level-p<l):
                ans = path_w
                l = level - p

            for y, w in e[x]:
                if y != pre:
                    dfs(y, level+1, p, tot_w+w, x)

            pref.pop()
            vis[a[x]] = prev_x

        dfs(0)
        return [ans, l]
