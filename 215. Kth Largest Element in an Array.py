class Solution:
    def findKthLargest(self, a: List[int], k: int) -> int:
        k -= 1
        def partition(a: List[int], l: int, r: int):
            k, x = l, a[(l+r)>>1]
            while k <= r:
                if a[k]==x:
                    k += 1
                elif a[k]<x:
                    a[k], a[r] = a[r], a[k]
                    r -= 1
                else:
                    a[l], a[k] = a[k], a[l]
                    l += 1
                    k += 1
            return x, l
            
        l, r = 0, len(a)-1
        while l < r:
            x, p = partition(a, l, r)
            if p==k:
                return x
            elif p > k:
                r = p-1
            else:
                l = p+1
        return a[l]
            