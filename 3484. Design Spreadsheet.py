class Spreadsheet:

    def parse(self, c: str):
        return c[0], int(c[1:])

    def __init__(self, rows: int):
        self.a = {chr(k):[0]*(rows+1) for k in range(ord('A'), ord('Z')+1)}

    def setCell(self, cell: str, value: int) -> None:
        i, j = self.parse(cell)
        self.a[i][j] = value

    def resetCell(self, cell: str) -> None:
        i, j = self.parse(cell)
        self.a[i][j] = 0

    def getValue(self, formula: str) -> int:
        if formula[0] == '=':
            c1, c2 = formula[1:].split('+')
            return self.getValue(c1) + self.getValue(c2)
        elif formula[0].isdigit():
            return int(formula)
        else:
            i, j = self.parse(formula)
            return self.a[i][j]


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
