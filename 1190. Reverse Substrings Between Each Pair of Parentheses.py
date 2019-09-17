class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        pr, stk = [0] * n, []
        for i in range(n):
            if s[i] == '(':
                stk.append(i)
            elif s[i] == ')':
                j = stk.pop()
                pr[i], pr[j] = j, i
        i, d, ans = 0, 1, ""
        while i < n:
            if s[i].isalpha():
                ans += s[i]
            else:
                i, d = pr[i], -d
            i += d
        return ans
                
                
        