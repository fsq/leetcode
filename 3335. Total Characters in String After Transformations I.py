class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = Counter(s)
        l = len(s)
        M = int(1e9 + 7)
        for _ in range(t):
            l = (l + cnt['z']) % M
            nxt = defaultdict(int)
            for c in range(ord('a'), ord('z')):
                nxt[chr(c+1)] = cnt[chr(c)]
            nxt['a'] = (nxt['a'] + cnt['z']) % M
            nxt['b'] = (nxt['b'] + cnt['z']) % M
            cnt = nxt
        return l