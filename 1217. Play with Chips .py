class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        od = sum(1 for x in chips if x&1)
        return min(od, len(chips)-od)