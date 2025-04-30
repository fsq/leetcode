class Solution:
    def countOfSubstrings(self, s: str, k: int) -> int:
        ans = 0
        for l in range(0, len(s)):
            st = set()
            con = 0
            for r in range(l, len(s)):
                if s[r] in "aeiou":
                    st.add(s[r])
                else:
                    con += 1
                if len(st)==5 and con==k:
                    ans += 1
        return ans
