class Solution:

    def maxSubarraySum(self, a: List[int]) -> int:
        pref_sum = 0
        min_pref_sum = 0
        f = {} # f[x] = min(prefix[i-1] + x * number of x in [i, j]), for all i
        min_f = 0
        ans = -inf
        for x in a:
            pref_sum += x
            ans = max(ans, pref_sum - min_f)
            if x < 0:
                if x in f:
                    f[x] = min(f[x]+x, min_pref_sum+x) # To cover i from last x till now
                else:
                    f[x] = min_pref_sum + x
                min_f = min(min_f, f[x])
            min_pref_sum = min(min_pref_sum, pref_sum)
            min_f = min(min_f, min_pref_sum)

        return ans


    def maxSubarraySumSegTree(self, a: List[int]) -> int:
        if len(set(a))==1 and a[0]<0:
            return a[0]
        negs = set()
        pos = defaultdict(list)
        pf = list(itertools.accumulate(a))
        ans = sum(a)

        for i, x in enumerate(a):
            if x < 0:
                negs.add(x)
                pos[x].append(i)
        
        if not negs:
            return ans

        # (max_subarray, max_subarray start from left, ... from right, array sum)
        tree = dict()
        def build(i, l, r):
            if l == r:
                tree[i] = (a[l],) * 4
            else:
                m = (l + r) >> 1
                lf = build(i*2, l, m)
                rt = build(i*2+1, m+1, r)
                tree[i] = (
                    max(lf[0], rt[0], lf[2]+rt[1]),
                    max(lf[1], lf[3]+rt[1]),
                    max(rt[2], rt[3]+lf[2]),
                    pf[r] - (pf[l-1] if l >0 else 0)
                )
            return tree[i]
        
        def calc(i, l, r, x):
            if l == r:
                if a[l]==x:
                    # a[l] is removed, f, p, q, should all be -inf
                    return (-inf, -inf, -inf, 0)
                else:
                    return tree[i]
            num_x = bisect_right(pos[x], r) - bisect_left(pos[x], l)
            if num_x == 0:
                return tree[i]

            m = (l + r) >> 1
            lf = calc(i*2, l, m, x) # f, p, q, s
            rt = calc(i*2+1, m+1, r, x) # f, p, q, s
            
            ret= (
                max(lf[0], rt[0], lf[2]+rt[1]),
                max(lf[1], lf[3]+rt[1]),
                max(rt[2], rt[3]+lf[2]),
                pf[r] - (pf[l-1] if l >0 else 0) + (-x)*num_x
            )
            return ret

        build(1, 0, len(a)-1)
        for x in negs:
            f = calc(1, 0, len(a)-1, x)[0]
            ans = max(ans, f)
        return ans
