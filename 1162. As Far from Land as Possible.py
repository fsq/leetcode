class Solution:
    def maxDistance(self, a: List[List[int]]) -> int:
        n = len(a)
        q = [(x,y) for x in range(n) for y in range(n) if a[x][y]]
        ans = -1
        for x,y in q:
            for tx,ty in (x+1, y), (x, y+1), (x-1, y), (x, y-1):
                if 0<=tx<n and 0<=ty<n and a[tx][ty]==0:
                    a[tx][ty] = a[x][y] + 1
                    q.append((tx, ty))
                    ans = max(ans, a[tx][ty]-1)
        return ans