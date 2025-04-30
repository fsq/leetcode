class Solution:
    def kthCharacter(self, k: int, op: List[int]) -> str:
        k -= 1
        def f(op, l, k):
            if k == 0:
                return "a"
            if k < l // 2:
                return f(op[:-1], l//2, k)
            else:
                c = f(op[:-1], l//2, k-l//2)
                if op[-1] == 0:
                    return c
                else:
                    return chr((ord(c)-ord('a')+1)%26 + ord('a'))
        
        return f(op[:k.bit_length()], 2**k.bit_length(), k)
