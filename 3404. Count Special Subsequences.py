class Solution:
    def numberOfSubsequences(self, a: List[int]) -> int:
        n = defaultdict(int)

        for i in range(1, len(a)):
            for j in range(i+2, len(a)):
                n[a[j]/a[i]] += 1

        ans = 0
        for r in range(len(a)):
            m = defaultdict(int)
            for i in range(r-1):
                m[a[i] / a[r]] += 1
            for j in range(r+3, len(a)):
                n[a[j] / a[r+1]] -= 1
            for k in m.keys():
                ans += m[k] * n.get(k, 0)
        return ans

