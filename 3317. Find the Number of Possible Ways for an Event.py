m = int(1e9 + 7)
cb = [[0]*1001 for _ in range(1001)]
cb[0][0] = 1
for i in range(1, 1001):
    cb[i][0] = 1
    for j in range(1, 1001):
        cb[i][j] = (cb[i-1][j] + cb[i-1][j-1]) % m

class Solution:

    def numberOfWays(self, n: int, x: int, y: int) -> int:
        # given t stages, #ways to assign n to <=t stages = t^n
        # given t stages, #ways to assign n to exact t stages: 
        # ways[t] = t^n - C(t,1)*ways[t-1] - C(t,2)*ways[t-2]...
        # #ways to assign n to t stages among x stages: C(x, t)*ways[t]

        ans = 0
        ways = [0] * (min(n,x)+1)
        # can assign to 1...min(n,x) stages
        for t in range(1, min(n,x)+1):
            ways[t] = pow(t, n, m) % m
            for j in range(1, t):
                ways[t] = (ways[t] - cb[t][j] * ways[t-j] % m + m) % m

            assign = cb[x][t] * ways[t] % m
            ans = (ans + assign * pow(y, t, m)) % m
        return ans

