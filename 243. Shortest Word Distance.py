class Solution:
    def shortestDistance(self, a: List[str], s: str, t: str) -> int:
        p1, p2 = -1, -1
        ans = math.inf
        for i, v in enumerate(a):
            if v==s:
                p1 = i
            elif v==t:
                p2 = i
            if p1!=-1 and p2!=-1:
                ans = min(ans, abs(p1-p2))
        return ans