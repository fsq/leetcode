class Solution:
    def minZeroArray(self, a: List[int], queries: List[List[int]]) -> int:
        k = 0
        s = [0] * (len(a) + 1)
        acc = 0
        for i, x in enumerate(a):
            acc += s[i]
            while k < len(queries) and acc < x:
                l, r, v = queries[k]
                k += 1
                s[l] += v
                s[r+1] -= v
                if l <= i <= r:
                    acc += v
            if acc < x:
                return -1
        return k


        # binary search
        # def isZeroArray(a: List[int], queries: List[List[int]], k) -> bool:
        #     s = [0] * (len(a) + 1)
        #     for l, r, v in queries[:k]:
        #         s[l] += v
        #         s[r+1] -= v
            
        #     s = list(accumulate(s))
        #     return all([pref >= x for pref, x in zip(s, a)])
        
        # if not isZeroArray(a, queries, len(queries)):
        #     return -1
    
        # l, r = 0, len(queries)
        # while l < r:
        #     mid = (l + r) >> 1
        #     if isZeroArray(a, queries, mid):
        #         r = mid
        #     else:
        #         l = mid + 1
        
        # return l