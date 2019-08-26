class Solution:
    class Node:
        def __init__(self, s: str):
            self.name, t, v, self.dst = s.split(",");
            self.ori = s
            self.t = int(t)
            self.v = int(v)
            
        
    def invalidTransactions(self, ts: List[str]) -> List[str]:
        n = len(ts)
        a = sorted([self.Node(s) for s in ts], key = lambda node: node.t)
        
        q = collections.deque()
        ans = set()
        h = collections.defaultdict(set)
        for i, x in enumerate(a):
            while len(q) and a[q[0]].t < x.t-60:
                h[a[q[0]].name].remove(q[0])
                q.popleft()
            if x.v > 1000:
                ans.add(i)
            for p in h[x.name]:
                if a[p].dst != x.dst:
                    ans.add(p)
                    ans.add(i)
            q.append(i)
            h[x.name].add(i);
        
        return [a[x].ori for x in ans]
        
        