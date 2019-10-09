class Solution:
    def longestSubsequence(self, a: List[int], df: int) -> int:
        m = collections.defaultdict(int)
        for x in a:
            m[x] = m[x-df] + 1
        return max(m.values())
        