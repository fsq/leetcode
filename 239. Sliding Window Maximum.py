class Solution:
    def maxSlidingWindow(self, a: List[int], k: int) -> List[int]:
        s, ans = collections.deque(), []
        for i, x in enumerate(a):
            while s and x >= a[s[-1]]: s.pop()
            s.append(i)
            if i >= k-1:
                if s[0] <= i-k: s.popleft()
                ans.append(a[s[0]])
        return ans