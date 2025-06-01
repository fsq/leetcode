class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:
        right = []
        left = []
        for a in range(26):
            d1 = [0] * 26
            d2 = [0] * 26
            nxt = prev = 0
            i = j = a
            for _ in range(25):
                nxt += nextCost[i]
                prev += previousCost[j]
                d1[(i + 1) % 26] = nxt
                d2[(j + 25) % 26] = prev
                i = (i + 1) % 26
                j = (j + 25) % 26
            right.append(d1)
            left.append(d2)

        ans = 0
        for a, b in zip(list(s), list(t)):
            ans += min(left[ord(a)-97][ord(b)-97], right[ord(a)-97][ord(b)-97])
        return ans

