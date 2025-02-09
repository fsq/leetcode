class Solution:
    def maximumPoints(self, a: List[int], e: int) -> int:
        target = min(a)
        if e < target:
            return 0
        return (e + sum(a) - target) // target