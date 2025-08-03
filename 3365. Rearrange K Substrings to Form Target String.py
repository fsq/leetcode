class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        f = defaultdict(int)
        l = len(s) // k
        for i in range(0, len(s), l):
            f[s[i:i+l]] += 1
        for i in range(0, len(t), l):
            ss = t[i:i+l]
            if ss not in f or not f[ss]:
                return False
            f[ss] -= 1
        return True
