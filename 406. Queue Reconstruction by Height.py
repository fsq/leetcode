class Solution:
    def reconstructQueue(self, a: List[List[int]]) -> List[List[int]]:
        ans = []
        for h,k in sorted(a, key=lambda x: (-x[0], x[1])):
            ans.insert(k, [h,k])
        return ans