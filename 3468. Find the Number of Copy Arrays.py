class Solution:
    def countArrays(self, a: List[int], bounds: List[List[int]]) -> int:
        ans = bounds[0]
        for i in range(1, len(a)):
            ans[0] += a[i] - a[i-1]
            ans[1] += a[i] - a[i-1]
            ans[0] = max(ans[0], bounds[i][0])
            ans[1] = min(ans[1], bounds[i][1])
            if ans[0] > ans[1]:
                return 0
        return ans[1]-ans[0]+1
