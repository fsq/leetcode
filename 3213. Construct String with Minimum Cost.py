import queue
class Solution:
    def minimumCost(self, target: str, ws: List[str], cs: List[int]) -> int:
        inf = 0x3f3f3f3f

        class Node:
            def __init__(self):
                self.cost = inf
                self.c = {}
                self.l = 0
                # https://cp-algorithms.com/string/aho_corasick.html#bfs-based-construction
                # link to the longest suffix node
                self.suffix_link = None
                # link to the longest suffix node where cost!=inf
                # required to jump through distinct length to achieve sqrt(N)
                self.cost_suffix_link = None 

        root = Node()
        for w, cost in zip(ws, cs):
            cur = root
            l = 0
            for c in w:
                if c not in cur.c:
                    cur.c[c] = Node()
                cur = cur.c[c]
                l += 1
                cur.l = l
            cur.cost = min(cur.cost, cost)
        
        # compute suffix link and transition
        q = queue.Queue()
        root.cost_suffix_link = root
        for c in string.ascii_lowercase:
            if c in root.c:
                root.c[c].suffix_link = root.c[c].cost_suffix_link = root
                q.put(root.c[c])
            else:
                root.c[c] = root
        while not q.empty():
            u = q.get()
            v = u.suffix_link
            for c in string.ascii_lowercase:
                if c in u.c:
                    tu = u.c[c]
                    tv = v.c[c]
                    tu.suffix_link = tv
                    tu.cost_suffix_link = tv if tv.cost!=inf else tv.cost_suffix_link
                    q.put(tu)
                else:
                    u.c[c] = v.c[c]

        f = [inf] * len(target)
        cur = root
        for i in range(len(target)):
            x = target[i]
            cur = cur.c[x]
            u = cur if cur.cost!=inf else cur.cost_suffix_link
            while u != root:
                f[i] = min(f[i], (f[i-u.l] if i>=u.l else 0) + u.cost)
                u = u.cost_suffix_link
        return -1 if f[-1]==inf else f[-1]

        