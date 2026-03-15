class Solution:
    def numOfUnplacedFruits(self, a: List[int], b: List[int]) -> int:
        sb = sorted([(x, i) for i, x in enumerate(b)])
        t = [0] * (1 << (len(a).bit_length() + 1))

        def build(i, l, r):
            if l == r:
                t[i] = (sb[l][1], l)
            else:
                m = (l + r) >> 1
                build(i*2, l, m)
                build(i*2+1, m+1, r)
                t[i] = min(t[i*2], t[i*2+1])
        
        def query(x, i=1, l=0, r=len(a)-1):
            if x <= l:
                return t[i]
            else:
                m = (l + r) >> 1
                if x > m:
                    return query(x, i*2+1, m+1, r)
                else:
                    return min(query(x, i*2, l, m), query(x, i*2+1, m+1, r))
        
        def update(x, i=1, l=0, r=len(a)-1):
            if l == r:
                t[i] = (inf, l)
            else:
                m = (l + r) >> 1
                if x <= m:
                    update(x, i*2, l, m)
                else:
                    update(x, i*2+1, m+1, r)
                t[i] = min(t[i*2], t[i*2+1])

        build(1, 0, len(sb)-1)
        ans = 0
        for v in a:
            l = bisect_left(sb, (v, -1))
            if l < len(sb):
                min_ind, j = query(l)
                # print(l, min_ind)
                if min_ind == inf:
                    ans += 1
                else:
                    update(j)
                    # print(t)
            else:
                ans += 1
        return ans
