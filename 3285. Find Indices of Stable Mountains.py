class Solution:
    def stableMountains(self, a: List[int], threshold: int) -> List[int]:
        return [i for i in range(1, len(a)) if a[i-1]>threshold]