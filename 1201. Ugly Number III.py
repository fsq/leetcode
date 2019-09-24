class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        
        def gcd(a, b):
            return a if b==0 else gcd(b, a%b)
        
        def lcm(a, b):
            return a * b / gcd(a, b)
        
        l, r = 1, int(2e9)
        while l < r:
            m = (l + r) >> 1
            cnt = m//a + m//b + m//c - m//lcm(a, b) - m//lcm(a,c) - m//lcm(b,c) + m//lcm(a,lcm(b,c))
            if cnt >= n:
                r = m
            else:
                l = m + 1
        return l