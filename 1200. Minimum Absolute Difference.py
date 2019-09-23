class Solution:
    def minimumAbsDifference(self, a: List[int]) -> List[List[int]]:
        a.sort()
        mn = min(b-a for a,b in zip(a, a[1:]))
        return [[a,b] for a,b in zip(a, a[1:]) if b-a==mn]
            