class Solution:
    def minMaxSubarraySum(self, a: List[int], k: int) -> int:
        n = len(a)
        def find_larger(a):
            p = [[-1, n] for _ in range(n)]
            q = deque()
            for i in range(len(a)):
                while len(q) and a[q[-1]]<a[i]:
                    p[q[-1]][1] = i
                    q.pop()
                if len(q):
                    p[i][0] = q[-1]
                q.append(i)
            return p

        def calc(p):
            ans = 0
            for i in range(n):
                l, r = p[i]
                x = min(k-1, i - l - 1)
                y = min(k-1, r - i - 1)
                # tot subarrays
                tot = (x+1) * (y+1)
                # minus longer than k
                longer = (x+y+1-k+1)*(x+y+1-k) // 2 if x+y+1-k>0 else 0
                ans = ans + (tot-longer) * a[i]
            return ans

        ans1 = calc(find_larger(a))
        ans2 = calc(find_larger([-x for x in a]))
        return ans1 + ans2
