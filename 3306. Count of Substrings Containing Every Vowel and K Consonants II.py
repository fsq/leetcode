class Solution:
    def countOfSubstrings(self, s: str, k: int) -> int:
        ans = l = r = vo = con = 0
        vd = defaultdict(int)
        vs = "aeiou"
        cont = [0] * (len(s) + 1) # continuous vowel
        for i in range(len(s)-1, -1, -1):
            if s[i] in vs:
                cont[i] = 1 + cont[i+1]
        while l < len(s):
            while r<len(s):
                is_v = s[r] in vs
                if is_v and (vo<5 or con<k):
                    if vd[s[r]]==0:
                        vo += 1
                    vd[s[r]] += 1
                    r += 1
                elif con<k and not is_v:
                    con += 1
                    r += 1
                else:
                    break
            if con == k and vo == 5:
                ans += 1 + cont[r]
            if s[l] in vs:
                if vd[s[l]]==1:
                    vo -= 1
                vd[s[l]] -= 1
            else:
                con -= 1
            l += 1
        return ans
