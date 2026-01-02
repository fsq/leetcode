import queue
class Solution:
    def supersequences(self, ws: List[str]) -> List[List[int]]:

        def ok(freq):
            vis = [0] * 26
            e = [[] for _ in range(26)]
            for w in ws:
                x = ord(w[0]) - ord('a')
                y = ord(w[1]) - ord('a')
                if freq[x]==2 or freq[y]==2:
                    continue
                e[x].append(y)
            def dfs(x, vis):
                vis[x] = 1
                for y in e[x]:
                    if vis[y] == 1:
                        return True
                    elif vis[y] == 0 and dfs(y, vis):
                        return True
                vis[x] = 2
                return False
            for i, x in enumerate(freq):
                if x==1 and vis[i]==0 and dfs(i, vis):
                    return False
            return True

        chars = set()
        for w in ws:
            chars.add(w[0])
            chars.add(w[1])
        chars = list(chars)
        min_len = inf
        ans = []

        msks = [x for x in range(1<<len(chars))]
        msks.sort(key=lambda x: x.bit_count())

        for msk in msks:
            cur_len = len(chars) + msk.bit_count()
            if cur_len > min_len:
                break
            cur_ans = [0] * 26
            for i in range(len(chars)):
                if msk & (1<<i):
                    cur_ans[ord(chars[i])-ord('a')] = 2
                else:
                    cur_ans[ord(chars[i])-ord('a')] = 1

            if ok(cur_ans):
                if cur_len == min_len:
                    ans.append(cur_ans)
                else:
                    ans = [cur_ans]
                    min_len = cur_len
        return ans
