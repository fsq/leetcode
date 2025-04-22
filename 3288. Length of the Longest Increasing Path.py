class Solution:
    def maxPathLength(self, a: List[List[int]], k: int) -> int:
        left = []
        right = []
        for x, y in a:
            if x < a[k][0] and y < a[k][1]:
                left.append((x, y))
            elif x > a[k][0] and y > a[k][1]:
                right.append((x, y))
        
        left.sort(key = lambda t: (t[0], -t[1]))
        right.sort(key = lambda t: (t[0], -t[1]))
        
        def find(a):
            q = []
            for _, x in a:
                i = bisect_left(q, x) # find first one >= x
                if i == len(q):
                    q.append(x)
                else:
                    q[i] = x
            return len(q)

        return find(left) + 1 + find(right)