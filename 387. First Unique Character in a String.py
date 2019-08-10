class Solution:
    def firstUniqChar(self, s: str) -> int:
        hm = collections.Counter(s)
        for i, j in enumerate(s):
            if hm[j] == 1:
                return i
        return -1
        
class Solution:
    def firstUniqChar(self, s: str) -> int:
        return min([s.index(c) for c in string.ascii_lowercase if s.count(c)==1 ] or [-1])
        