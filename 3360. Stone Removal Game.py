class Solution:
    def canAliceWin(self, n: int) -> bool:
        turn = False
        take = 10
        while n >= take:
            turn = not turn
            n -= take
            take -= 1
        return turn