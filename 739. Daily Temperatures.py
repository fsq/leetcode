class Solution:
    def dailyTemperatures(self, a: List[int]) -> List[int]:
        q = []
        ans = [0] * len(a)
        for i,x in enumerate(a):
            while q and a[q[-1]]<x:
                pre = q.pop()
                ans[pre] = i - pre
            q.append(i)
        return ans
                