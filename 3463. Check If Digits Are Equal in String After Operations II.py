class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)

        # p must be prime
        def lucas(a, b, p):
            if b==0:
                return 1
            return comb(a%p, b%p) * lucas(a//p, b//p, p) % p

        def eq(p):
            x = 0
            for i in range(n-1):
                c = lucas(n-2, i, p)
                x = (x + (int(s[i])-int(s[i+1])+p) * c) % p
            return x == 0

        # a=b (%10) ==> a=b(%2) && a=b(%5)
        return eq(2) and eq(5)
