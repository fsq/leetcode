class Solution:
    def validStrings(self, n: int) -> List[str]:
        ans = []

        def dfs(cur:List[str], i:int):
            if i == n:
                ans.append(''.join(cur))
            else:
                if cur[-1]=='1':
                    cur.append('0')
                    dfs(cur, i+1)
                    cur[-1] = '1'
                    dfs(cur, i+1)
                    cur.pop()
                else:
                    cur.append('1')
                    dfs(cur, i+1)
                    cur.pop()
                

        dfs(['0'], 1)
        dfs(['1'], 1)
        return ans