class Solution:
    def sortMatrix(self, a: List[List[int]]) -> List[List[int]]:
        for si in range(len(a)):
            e = sorted([a[i][i-si] for i in range(si, len(a))], key=lambda x: -x)
            for i in range(si, len(a)):
                a[i][i-si] = e[i-si]
        for sj in range(1, len(a[0])):
            e = sorted([a[j-sj][j] for j in range(sj, len(a))])
            for j in range(sj, len(a)):
                a[j-sj][j] = e[j-sj]
        return a
