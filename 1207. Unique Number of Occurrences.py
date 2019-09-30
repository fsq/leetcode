class Solution:
    def uniqueOccurrences(self, a: List[int]) -> bool:
        c = collections.defaultdict(int)
        for x in a:
            c[x] += 1
        return len(set(c.values())) == len(c)