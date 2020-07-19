class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        
        fn = lambda x, y: sum(sqrt((x-a)**2 + (y-b)**2) for a, b in positions)
        x, y = 0, 0
        ans = fn(x, y)
        alpha = 100
        while alpha > 1e-6:
            zoom = True
            for dx, dy in (-1, 0), (0, -1), (0, 1), (1, 0):
                xt = x + alpha * dx
                yt = y + alpha * dy
                d = fn(xt, yt)
                if d < ans: 
                    ans = d 
                    x, y = xt, yt
                    zoom = False 
                    break 
            if zoom: alpha /= 2
        return ans 