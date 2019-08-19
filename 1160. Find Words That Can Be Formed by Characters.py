class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        st = collections.Counter(chars)
        cs = [collections.Counter(s) for s in words]
        return sum([len(s) for i,s in enumerate(words) if all(st[c]>=cs[i][c] for c in cs[i])])