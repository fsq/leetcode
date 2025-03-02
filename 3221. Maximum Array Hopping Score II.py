class Solution:
    def maxScore(self, a: List[int]) -> int:
        q = deque()
        for i, x in enumerate(a):
            while len(q) and q[-1][0]<x:
                q.pop()
            q.append([x, i])

        ans = 0
        i = 0
        for x, j in q:
            ans += (j - i) * x
            i = j
        return ans