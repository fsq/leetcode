class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        m = collections.Counter(frozenset(w) for w in words)
        ans = []
        for p in puzzles:
            x = 0
            st = [p[0]]
            for c in p[1:]:
                st += [s + c for s in st]
            ans.append(sum(m[frozenset(w)] for w in st))
        return ans