class Solution:
    def numOfUnplacedFruits(self, a: List[int], b: List[int]) -> int:
        unplaced = len(a)
        for x in a:
            for j in range(len(b)):
                if b[j] >= x:
                    del b[j]
                    unplaced -= 1
                    break
        return unplaced