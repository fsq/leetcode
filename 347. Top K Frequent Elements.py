class Solution:
    def topKFrequent(self, a: List[int], k: int) -> List[int]:
        return [x for x,c in collections.Counter(a).most_common(k)]