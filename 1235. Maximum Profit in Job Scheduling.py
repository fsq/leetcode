class Solution:
    def jobScheduling(self, start: List[int], end: List[int], profit: List[int]) -> int:
        ed = collections.defaultdict(list)
        for i, r in enumerate(end):
            ed[r].append(i)
        s = list(set(start).union(end))
        s.sort()
        
        f = collections.defaultdict(int)
        for i,r in enumerate(s):
            f[r] = 0 if i==0 else f[s[i-1]]
            for ind in ed[r]:
                f[r] = max(f[r], f[start[ind]] + profit[ind])
        
        return max(f.values())
        
        
        