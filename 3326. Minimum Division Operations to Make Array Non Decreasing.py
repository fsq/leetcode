class Solution:
    def minOperations(self, a: List[int]) -> int:
        ans = 0

        @cache
        def div(x):
            if x == 1:
                return 1
            for i in range(2, int(sqrt(x))+1):
                if x % i == 0:
                    return i
            return x

        for i in reversed(range(len(a)-1)):
            if a[i] > a[i+1]:
                a[i] = div(a[i])
                if a[i] > a[i+1]:
                    return -1
                ans += 1
        return ans