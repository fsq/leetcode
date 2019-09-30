class Solution:
    def maxRepOpt1(self, s: str) -> int:
        n = len(s)
        c = collections.Counter(s)
        a = [[x, len(list(it))] for x,it in itertools.groupby(s)]
        ans = max(min(c[x], l+1) for x,l in a)
        for i in range(1, len(a)-1):
            if a[i-1][0]==a[i+1][0] and a[i][1]==1:
                ans = max(ans, min(a[i-1][1]+a[i+1][1]+1, c[a[i-1][0]]))
        return ans
        