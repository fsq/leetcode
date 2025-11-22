class Solution:
    def calculateScore(self, s: str) -> int:
        def mirror(c):
            return chr(25-(ord(c)-ord('a')) + ord('a'))
        ans = 0
        d = defaultdict(list)
        for i, c in enumerate(s):
            m = mirror(c)
            if len(d[m]):
                ans += i - d[m].pop()
            else:
                d[c].append(i)
        return ans

