class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        d = defaultdict(int)
        points = Counter(nums)
        for x in nums:
            d[x-k] += 1
            d[x] += 0
            d[x+k] += 0
            d[x+k+1] -= 1
        
        pref = 0
        ans = 0
        for x in sorted(d.keys()):
            pref += d[x]
            ans = max(ans, min(points[x]+numOperations, pref))

        return ans
        