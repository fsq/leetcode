class Solution:
    def maxWeight(self, a: List[int]) -> int:
        a.sort(reverse=True)
        pk = len(a) // 4
        odd = (pk+1) // 2
        even = pk - odd
        ans = sum(a[:odd]) + sum(a[odd+1:odd+even*2:2])
        return ans
