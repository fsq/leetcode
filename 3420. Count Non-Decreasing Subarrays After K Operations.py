class Solution:
    def countNonDecreasingSubarrays(self, a: List[int], k: int) -> int:
        a.reverse()
        q = deque()
        budget = i = ans = 0
        for j in range(len(a)):
            while len(q) and a[j]>a[q[-1]]:
                l = q[-1]-q[-2] if len(q)>1 else q[-1]-i+1
                budget += l * (a[j] - a[q[-1]])
                q.pop()
            q.append(j)
            while budget > k:
                if q[0] == i:
                    q.popleft()
                else:
                    budget -= a[q[0]] - a[i]
                i += 1
            ans += j - i + 1
        return ans

