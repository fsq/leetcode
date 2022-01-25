class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        ans = eval(s)
        m = dict()

        score = 0
        def dfs(s: str, l:int, r:int):
            if s[l:r] in m:
                return m[s[l:r]]
            if l==r-1:
                return set([eval(s[l])])
            else:
                ns = set()
                for i in range(l, r):
                    if s[i]=='+' or s[i]=='*':
                        s1 = dfs(s, l, i)
                        s2 = dfs(s, i+1, r)
                        for x in s1:
                            for y in s2:
                                if s[i]=='+' and x+y<=1000:
                                    ns.add(x + y)
                                elif s[i]=='*' and x*y<=1000:
                                    ns.add(x * y)
                m[s[l:r]] = ns
                return m[s[l:r]]
        
        all_ans = dfs(s, 0, len(s))
        
        for x in answers:
            if x == ans:
                score += 5
            elif x in all_ans:
                score += 2
                
        return score
            