class Solution:

    def clear(a: list):
        pre = -1
        for i, c in enumerate(a):
            if c.isdigit():
                del a[i]
                if pre != -1:
                    del a[pre]
                return True
            else:
                pre = i
        return False


    def clearDigits(self, s: str) -> str:
        a = list(s)
        while Solution.clear(a):
            pass
        return ''.join(a)