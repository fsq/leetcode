class Solution:
    def findXSum(self, a: List[int], k: int, x: int) -> List[int]:
        return [
            sum([y*f for f, y in
                sorted([[f, x] for x, f in Counter(a[i:i+k]).items()], reverse=True)[:x]])
            for i in range(len(a)-k+1)
        ]
