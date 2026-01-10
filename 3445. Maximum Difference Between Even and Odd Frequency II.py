class Solution:
    def maxDifference(self, st: str, k: int) -> int:
        # f[i][ab][pq] = max_0..i (s[i][a]-s[i][b]) where s[i][a]&1==p and s[i][b]&1==q
        f = [[[inf for _ in range(4)] for _ in range(25)] for _ in range(len(st))]
        for a in range(5):
            for b in range(5):
                f[0][a*5+b][0] = 0
        ans = -inf
        s = [[0]* 5]
        for i in range(len(st)):
            t = s[-1][:]
            t[ord(st[i]) - ord('0')] += 1
            s.append(t)
        last = [0] * 5 # to ensure at least one b in subarr
        for i, x in enumerate(st):
            i += 1
            j = i - k
            if j > 0:
                for a in range(5):
                    for b in range(5):
                        f[j][a*5+b] = f[j-1][a*5+b][:]
                        p = s[j][a] & 1
                        q = s[j][b] & 1
                        f[j][a*5+b][p<<1 | q] = min(f[j][a*5+b][p<<1 | q], s[j][a]-s[j][b])
            if j >= 0:
                for a in range(5):
                    p = s[i][a] & 1
                    for b in range(5):
                        jt = min(j, last[b]-1)
                        q = s[i][b] & 1
                        if jt >= 0:
                            ans = max(ans, (s[i][a] - s[i][b]) - f[jt][a*5+b][(p^1) << 1 | q])
            last[ord(x)-ord('0')] = i

        return ans
