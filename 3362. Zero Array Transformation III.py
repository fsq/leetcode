class Solution:
    def maxRemoval(self, a: List[int], qs: List[List[int]]) -> int:
        qs.sort()
        j = cur = ans = 0
        s = [0] * (len(a) + 1)
        available = []
        for i in range(len(a)):
            cur += s[i]
            while j<len(qs) and qs[j][0]==i:
                heappush(available, -qs[j][1])
                j += 1
            while cur < a[i] and len(available) > 0:
                r = -heappop(available)
                if r >= i:
                    ans += 1
                    cur += 1
                    s[r+1] -= 1
            if cur < a[i]:
                return -1
        return len(qs) - ans
            
