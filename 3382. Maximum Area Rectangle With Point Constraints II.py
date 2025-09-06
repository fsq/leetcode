class Solution:
    def maxRectangleArea(self, xs: List[int], ys: List[int]) -> int:
        ps = defaultdict(set)
        all_y = set()
        for x, y in zip(xs, ys):
            ps[x].add(y)
            all_y.add(y)
        y2i = {}
        for i, y in enumerate(sorted(list(all_y))):
            y2i[y] = i
        n = len(all_y)
        tree = [-inf] * (1 << (n.bit_length() + 1))

        def update(key, val, i=1, l=0, r=n-1):
            if l == r:
                tree[i] = val
            else:
                mid = (l+r) >> 1
                if key <= mid:
                    update(key, val, i*2, l, mid)
                else:
                    update(key, val, i*2+1, mid+1, r)
                tree[i] = max(tree[i*2], tree[i*2+1])
        
        def query(x1, x2, i=1, l=0, r=n-1):
            if x1 > x2:
                return -inf
            if x1<=l and r<=x2:
                return tree[i]
            mid = (l+r) >> 1
            y1 = query(x1, x2, i*2, l, mid) if x1<=mid else -inf
            y2 = query(x1, x2, i*2+1, mid+1, r) if x2>mid else -inf
            return max(y1, y2)
            

        ans = -1
        max_x = defaultdict(lambda: -inf)
        for x2 in sorted(ps.keys()):
            ys = sorted(list(ps[x2]))
            for y1, y2 in pairwise(ys):
                x1 = max_x[y1]
                if x1!=-inf and x1==max_x[y2]:
                    if y1 in ps[x1] and y2 in ps[x1] and query(y2i[y1]+1, y2i[y2]-1)<x1:
                        ans = max(ans, (y2-y1) * (x2-x1))
            for y in ys:
                max_x[y] = x2
                update(y2i[y], x2)
        return ans
