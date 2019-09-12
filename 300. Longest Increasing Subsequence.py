class Solution:
    def lengthOfLIS(self, a: List[int]) -> int:
        s = []
        for x in a:
            i = bisect.bisect_left(s, x) # >= x
            if i==len(s):
                s.append(x)
            else:
                s[i] = x
        return len(s)
                