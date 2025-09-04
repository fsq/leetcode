class Solution:
    def countComponents(self, nums: List[int], threshold: int) -> int:
        nums.sort()
        fa = {x: x for x in range(threshold+1)}
        def find(x):
            if fa[x] != x:
                fa[x] = find(fa[x])
            return fa[x]

        for x in nums:
            if x > threshold:
                break
            fx = find(x)
            for y in range(x*2, threshold+1, x):
                if y not in fa:
                    continue
                fy = find(y)
                fa[fy] = fx

        return len([1 for x in nums if x not in fa or fa[x]==x])
