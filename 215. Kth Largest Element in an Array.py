class Solution:
    def findKthLargest(self, a: List[int], k: int) -> int:

        def partition(a: List[int], l: int, r: int):
            x = a[(l+r) // 2]
            # [0, i) > x
            # [i, j) ==x 
            # (k, r] < x
            i, j, k = l, l, r
            while j <= k:
                if a[j] > x:
                    a[i], a[j] = a[j], a[i]
                    j += 1
                    i += 1
                elif a[j] == x:
                    j += 1
                else:
                    a[j], a[k] = a[k], a[j]
                    k -= 1
            return i, k

        k -= 1
        l, r = 0, len(a)-1
        while l < r:
            el, er = partition(a, l, r)
            if el<=k and k<=er:
                return a[k]
            elif er < k:
                l = er + 1
            else:
                r = el - 1
        return a[l]