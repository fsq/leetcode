class SegTree:
    def __init__(self, n, xc):
        self.n = n
        self.tn = 1 << (n.bit_length() + 1)
        self.covered = [0] * self.tn
        self.len = [0] * self.tn
        self.xc = xc
    
    def update(self, delta, l, r):
        self._update(1, 0, self.n-1, delta, l, r)

    def _update(self, i, lt, rt, delta, l, r):
        if l<=lt and rt<=r:
            self.covered[i] += delta
        else:
            mid = (lt + rt) >> 1
            if l <= mid:
                self._update(i*2, lt, mid, delta, l, r)
            if r > mid:
                self._update(i*2+1, mid+1, rt, delta, l, r)
        if self.covered[i]:
            self.len[i] = self.xc[rt + 1] - self.xc[lt]
        elif lt != rt:
            self.len[i] = self.len[i*2] + self.len[i*2+1]
        else:
            self.len[i] = 0
        
    def query(self):
        return self.len[1]


class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        x_coords = set()
        for (x, y, l) in squares:
            x_coords.add(x)
            x_coords.add(x+l)
        x_coords = sorted(list(x_coords))
        x_to_index = {x: i for i, x in enumerate(x_coords)}
        n = len(x_to_index)

        e = []
        for (x, y, l) in squares:
            e.append([y, 1, x_to_index[x], x_to_index[x+l]-1])
            e.append([y+l, -1, x_to_index[x], x_to_index[x+l]-1])
        e.sort()

        seg = SegTree(n, x_coords)
        ei = cur_len = area = 0
        areas = []
        prev_y = e[0][0]
        while ei < len(e):
            cur_y = e[ei][0]
            area += cur_len * (cur_y - prev_y)
            areas.append((cur_y, area))
            while ei < len(e) and e[ei][0]==cur_y:
                seg.update(e[ei][1], e[ei][2], e[ei][3])
                ei += 1
            cur_len = seg.query()
            prev_y = cur_y
        
        target = areas[-1][1] / 2
        for (y1, a1), (y2, a2) in pairwise(areas):
            if a1 <= target <= a2:
                return y1 + (y2 - y1) * (target - a1) / (a2 - a1)
        
        return -1

            
