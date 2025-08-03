class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        a = [0, *list(itertools.accumulate(nums))]
        ans = inf
        for i in range(1, len(a)):
            for j in range(i+l-1, i+r):
                if j >= len(a):
                    break
                s = a[j] - a[i-1]
                if s > 0 and s < ans:
                    ans = s
        return ans if ans != inf else -1

