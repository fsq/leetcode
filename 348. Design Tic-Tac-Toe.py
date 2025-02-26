class TicTacToe:

    def __init__(self, n: int):
        self.r = [0] * n
        self.c = [0] * n
        self.d1 = self.d2 = 0
        self.n = n

    def move(self, row: int, col: int, player: int) -> int:
        x = 1 if player==1 else -1
        self.r[row] += x
        self.c[col] += x
        if row==col:
            self.d1 += x
        if row+col==self.n-1:
            self.d2 += x
        if abs(self.r[row])==self.n or abs(self.c[col])==self.n or abs(self.d1)==self.n or abs(self.d2)==self.n:
            return player
        else:
            return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)