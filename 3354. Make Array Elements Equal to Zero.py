class Solution:
    def countValidSelections(self, a: List[int]) -> int:
        ans = 0
        for i in range(len(a)):
            if a[i] != 0:
                continue
            for d in [-1, 1]:
                cur, dr = i, d
                b = a[:]
                while 0 <= cur < len(a):
                    if b[cur] == 0:
                        cur += dr
                    else:
                        b[cur] -= 1
                        dr *= -1
                        cur += dr
                if all([x==0 for x in b]):
                    ans += 1
        return ans