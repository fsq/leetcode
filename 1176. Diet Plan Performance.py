class Solution:
    def dietPlanPerformance(self, a: List[int], k: int, lower: int, upper: int) -> int:
        ans, s = 0, 0
        for i in range(len(a)):
            s += a[i]
            if i >= k:
                s -= a[i-k]
            if i >= k-1:
                if s > upper: ans += 1
                if s < lower: ans -= 1
        return ans