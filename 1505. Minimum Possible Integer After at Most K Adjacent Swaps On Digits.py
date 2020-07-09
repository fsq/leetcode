class Solution:
    def minInteger(self, num: str, k: int) -> str:
        d = defaultdict(deque)
        for i, c in enumerate(num):
            d[c].append(i)
        ans, done = '', []
        for _ in range(len(num)):
            for c in string.digits:
                if d[c]:
                    i = d[c][0]
                    cost = i - bisect.bisect(done, i)
                    if cost <= k:
                        k -= cost
                        ans += c
                        bisect.insort(done, d[c].popleft())
                        break
        return ans