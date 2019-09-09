class Solution:
    def distanceBetweenBusStops(self, a: List[int], x: int, y: int) -> int:
        if x > y:
            x, y = y, x
        s, d = sum(a), sum(a[x:y])
        return min(d, s-d)