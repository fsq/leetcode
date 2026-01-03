class Solution:
    def maxFreeTime(self, eventTime: int, k: int, a: List[int], b: List[int]) -> int:
        a.insert(0, 0)
        b.insert(0, 0)
        a.append(eventTime)
        b.append(eventTime)
        ans = 0
        s = [0]
        for i in range(1, len(a)):
            s.append(s[-1] + b[i]-a[i])
        for i in range(1, len(a)):
            j = min(i+k-1, len(a)-2)
            interval = a[j+1]-b[i-1] - (s[j]-s[i-1])
            ans = max(ans, interval)
        return ans
