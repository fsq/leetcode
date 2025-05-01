class Solution:
    def constructGridLayout(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        e = defaultdict(list)
        deg = defaultdict(int)
        d2x = defaultdict(list) # deg -> [nodes]
        for x, y in edges:
            e[x].append(y)
            deg[x] += 1
            e[y].append(x)
            deg[y] += 1
        for x, d in deg.items():
            d2x[d].append(x)
        
        # one row
        if 1 in d2x:
            x, pre, ans = d2x[1][0], -1, []
            while True:
                ans.append(x)
                y = [y for y in e[x] if y != pre]
                if len(y):
                    pre, x = x, y[0]
                else:
                    break
            return [ans]
        
        # rectangle
        x, row, pre = d2x[2][0], [], -1  # top-left corner
        vis = set()
        while True:
            row.append(x)
            vis.add(x)
            if deg[x]==2 and pre!=-1:
                break
            nxt = 0
            for y in e[x]:
                if y != pre:
                    # find deg2 neighbor if any
                    if deg[y] == 2:
                        nxt = y
                        break
                    elif deg[y] == 3:
                        nxt = y
            x, pre = nxt, x
        
        ans = [row]
        while len(vis) < n:
            row = []
            for x in ans[-1]:
                for y in e[x]:
                    if not y in vis:
                        row.append(y)
                        vis.add(y)
                        break
            ans.append(row)
        return ans



            
