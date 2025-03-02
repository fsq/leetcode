class Solution:
    def tripletCount(self, a: List[int], b: List[int], c: List[int]) -> int:
        ans = 0
        for x in a:
            for y in b:
                for z in c:
                    n = x ^ y ^ z
                    if not (n.bit_count() & 1):
                        ans += 1
        return ans
