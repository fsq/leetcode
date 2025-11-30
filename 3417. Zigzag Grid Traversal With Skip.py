class Solution:
    def zigzagTraversal(self, a: List[List[int]]) -> List[int]:
        for i, x in enumerate(a):
            if i % 2 == 1:
                x.reverse()
        return [x for i,x in enumerate(chain.from_iterable(a)) if i%2==0]
