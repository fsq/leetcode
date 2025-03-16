class Solution:
    def fixedRatio(self, st: str, num1: int, num2: int) -> int:
        n = len(st)
        s = 0
        d = defaultdict(int)
        d[0] = 1
        ans = 0
        for i in range(n):
            if st[i]=='1':
                s += 1
            k = (num1+num2)*s - num2*(i+1)
            ans += d[k]
            d[k] += 1
        return ans