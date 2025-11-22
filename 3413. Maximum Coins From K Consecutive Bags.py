class Solution:
    def maximumCoins(self, seg: List[List[int]], k: int) -> int:
        return max(self.solve(seg, k), self.solve([[-y, -x, c] for x,y,c in seg], k))

    def solve(self, seg: List[List[int]], k: int) -> int:
        seg.sort()
        cur_coins = 0
        ans = 0
        r = 0
        for l in range(len(seg)):
            while r<len(seg) and seg[r][0]-seg[l][0]+1<=k:
                cur_coins += (seg[r][1]-seg[r][0]+1) * seg[r][2]
                r += 1
            
            extra = max(0, seg[r-1][1]-seg[l][0]+1 - k)
            ans = max(ans, cur_coins - extra * seg[r-1][2])

            cur_coins -= (seg[l][1]-seg[l][0]+1) * seg[l][2]

        return ans
            
            
