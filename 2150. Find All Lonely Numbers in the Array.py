class Solution:
    def findLonely(self, a: List[int]) -> List[int]:
        d = Counter(a)
        return [x for x in a if d[x]==1 and not (x+1 in d) and not (x-1 in d)]