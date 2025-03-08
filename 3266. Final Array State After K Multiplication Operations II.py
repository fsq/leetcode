class Solution:
    def getFinalState(self, a: List[int], k: int, mult: int) -> List[int]:
        if mult == 1:
            return a
        heapq.heapify(q := list(zip(a, range(len(a)))))
        seen = set()
        # until multiply each one at least once
        # since now, each top*mutl will push to the bottom of heap
        # proof by contradiction:
        # say top = x*mult^a
        # if exist y, such that x*mult^(a+1) < y*mult^b
        # then x*mult^a < y*mult^(b-1), where b>0
        # notice left side is current top, this means current top < right side
        # then top must have been multiplied before y*mult^(b-1), y*mult^b shouldn't have existed
        while k and len(seen)<len(a):
            x, i = heapq.heappop(q)
            heapq.heappush(q, (x*mult, i))
            k -= 1
            seen.add(i)

        p = k // len(q)
        r = k % len(q)
        MOD = (int)(1e9 + 7)

        for qi in range(len(a)):
            x, ai = heappop(q)
            a[ai] = (x * pow(mult, p + (1 if qi<r else 0), MOD)) % MOD

        return a
