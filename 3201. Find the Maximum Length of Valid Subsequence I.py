import numpy as np

class Solution:
    def maximumLength(self, a: List[int]) -> int:
        cnt = [0, 0]
        pre = a[0] % 2
        ans = 1
        cnt[pre] += 1
        for i in range(1, len(a)):
            x = a[i] % 2
            cnt[x] += 1
            if x^pre == 1:
                ans += 1
                pre = x
        return max(*cnt, ans)

