class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        dr = {'N':0, 'E':1, 'S':2, 'W':3}
        dx = [0, 1, 0, -1]
        dy = [-1, 0, 1, 0]
        x, y, ans = 0, 0, 0
        for i, c in enumerate(s):
            r = dr[c]
            x += dx[r]
            y += dy[r]
            ans = max(ans, min(abs(x)+abs(y)+2*k, i+1))
        return ans
