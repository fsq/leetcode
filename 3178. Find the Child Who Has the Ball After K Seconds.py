class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        rev = k // (n-1) % 2;
        rem = k % (n-1);
        return rem if not rev else n-rem-1