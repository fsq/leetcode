class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        p = defaultdict(list)
        for i, x in enumerate(nums):
            p[x].append(i)
        ans = [-1] * len(nums)
        for a in p.values():
            if len(a)==1:
                continue
            for i, x in enumerate(a):
                prev = a[i-1] if i>0 else a[len(a)-1]
                nxt = a[i+1] if i+1<len(a) else a[0]
                ans[x] = min((x+len(nums)-prev)%len(nums), (nxt+len(nums)-x)%len(nums))
        return [ans[x] for x in queries]
