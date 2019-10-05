class Solution:
    def arraysIntersection(self, a: List[int], b: List[int], c: List[int]) -> List[int]:
        ans = []
        i = j = k = 0
        while i<len(a) and j<len(b) and k<len(c):
            if a[i]==b[j]==c[k]:
                ans.append(a[i])
                i += 1
                j += 1
                k += 1
            else:
                if a[i]<=b[j] and a[i]<=c[k]: i += 1
                elif b[j]<=a[i] and b[j]<=c[k]: j += 1
                else: k += 1
        return ans