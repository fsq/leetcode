class Solution:
    def maxRectangleArea(self, a: List[List[int]]) -> int:
        ans = -1
        for i in range(len(a)):
            x1, y1 = a[i]
            for j in range(i+1, len(a)):
                x2, y2 = a[j]
                if x1==x2 or y1==y2:
                    continue
                corners = 0
                ok = True
                for k in range(len(a)):
                    x, y = a[k]
                    if x in (x1, x2) and y in (y1, y2):
                        corners += 1
                        continue
                    if min(x1,x2) <= x <= max(x1,x2) and min(y1,y2) <= y <= max(y1,y2):
                        ok = False
                        break
                if corners == 4 and ok:
                    ans = max(ans, abs(y1-y2)*abs(x1-x2))
        return ans
