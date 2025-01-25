class Solution:
    def findWinningPlayer(self, a: List[int], k: int) -> int:
        winner, mx, row = 0, a[0], 0
        for id, val in enumerate(a[1:], start=1):
            if val > mx:
                winner = id
                mx = val
                row = 1
            else:
                row += 1
            if row == k:
                return winner
        return winner
