class Solution:
    # greedy proof at https://leetcode.cn/problems/lexicographically-smallest-generated-string/solutions/3592764/liang-chong-fang-fa-tan-xin-bao-li-pi-pe-gxyn/
    def generateString(self, tf: str, t: str) -> str:
        m = len(t)
        n = len(tf)
        a = [0] * (n + m - 1)
        for i, v in enumerate(tf):
            if v == 'T':
                for j in range(i, i+m):
                    if a[j]!=0 and a[j]!=t[j-i]:
                        return ""
                    a[j] = t[j - i]
        
        # empty slot
        p = []
        for i in range(len(a)):
            if a[i] == 0:
                p.append(i)
                a[i] = 'a'
        last = 0
        for i, v in enumerate(tf):
            if v == 'T':
                continue
            while last<len(p) and p[last]<i+m:
                last += 1
            if ''.join(a[i:i+m]) == t:
                if last>0 and p[last-1]>=i:
                    a[p[last-1]] = 'b'
                else:
                    return ""
        return ''.join(a)
