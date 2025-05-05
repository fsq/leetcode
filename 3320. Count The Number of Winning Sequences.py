class Solution:
    def countWinningSequences(self, s: str) -> int:
        n = len(s)
        m = int(1e9 + 7)
        f = defaultdict(lambda: [0]*3) # f[i][gap], gap=alice-bob=[-i, i]
        ind = {'F':0, 'W':1, 'E':2}
        f[0][ind[s[0]]] = 1
        f[1][(ind[s[0]]+2)%3] = 1
        f[-1][(ind[s[0]]+1)%3] = 1
        for i in range(1, n):
            g = defaultdict(lambda: [0]*3)
            for prev in range(3): # prev element
                for cur in range(3): # cur element
                    if prev != cur:
                        ofst = ind[s[i]] - cur
                        if abs(ofst) == 2: ofst = -ofst//2
                        for j in range(-i, i+1):  # prev gap
                            g[j+ofst][cur] = (g[j+ofst][cur] + f[j][prev]) % m
            f = g
        ans = 0
        for i in range(-n, 0):
            ans = (ans + sum(f[i])) % m
        return ans
        