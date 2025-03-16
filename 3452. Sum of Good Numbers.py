class Solution:
    def sumOfGoodNumbers(self, a: List[int], k: int) -> int:
        return sum([x for i,x in enumerate(a)
                        if (i-k<0 or x>a[i-k]) and
                           (i+k>=len(a) or x>a[i+k])])