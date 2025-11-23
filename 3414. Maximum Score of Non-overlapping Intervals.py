class Solution:
    def maximumWeight(self, a: List[List[int]]) -> List[int]:
        for i in range(len(a)):
            a[i].append(i)
        a.sort()
        rt = [bisect_right(a, a[i][1], key=lambda x: x[0]) for i in range(len(a))]
        
        # return [score, [indices]]
        @functools.lru_cache(maxsize=None)
        def dp(i, k):
            if k == 0 or i == len(a):
                return (0, ())
            sc1, ind1 = dp(i+1, k)
            sc2, ind2 = dp(rt[i], k-1)
            sc2 += a[i][2]
            ind2 = tuple(sorted(list(ind2) + [a[i][3]]))
            if sc1 < sc2 or (sc1==sc2 and ind1>ind2):
                return (sc2, ind2)
            else:
                return (sc1, ind1)
        
        return dp(0, 4)[1]
