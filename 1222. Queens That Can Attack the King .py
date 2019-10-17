class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        ans, p = [], {(x, y):True for x,y in queens}
        for dir in [[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1]]:
            x, y, dx, dy = king[0], king[1], dir[0], dir[1]
            while 0<=x<8 and 0<=y<8:
                if p.get((x, y)):
                    ans.append([x, y])
                    break
                x += dx
                y += dy
        return ans