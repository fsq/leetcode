class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        class Node:
            def __init__(self):
                self.s = dict()

        root = Node()
        for w in words:
            p = root
            for c in w:
                p = p.s.setdefault(c, Node())
        
        # print(s)
        @functools.cache
        def f(i):
            if i==len(target):
                return 0
            ans = inf
            p = root
            for j in range(i, len(target)):
                if target[j] in p.s:
                    p = p.s[target[j]]
                    nxt = f(j+1)
                    ans = min(ans, 1 + nxt)
                else:
                    break
            return ans
        ans = f(0)
        return -1 if ans==inf else ans
