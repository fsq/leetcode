class Node:
    def __init__(self):
        self.child = {}
        self.cnt = 0

class Solution:
    def longestCommonPrefix(self, words: List[str], k: int) -> List[int]:
        cnt_lens = defaultdict(int)  # len:cnt, count how many nodes with cnt>=k and depth len
        max_len = 0
        root = Node()
        for w in words:
            cur = root
            depth = 0
            for c in w:
                if c not in cur.child:
                    cur.child[c] = Node()
                cur = cur.child[c]
                depth += 1
                cur.cnt += 1
                if cur.cnt == k:
                    cnt_lens[depth] += 1
                    max_len = max(max_len, depth)

        # will always have a max_len prefix
        if cnt_lens[max_len] > 1:
            return [max_len] * len(words)
        
        ans = []
        for w in words:
            if len(w) < max_len:
                ans.append(max_len)
                continue

            cur = root
            depth = 0
            remain_max = max_len
            for c in w:
                depth += 1
                cur = cur.child[c]
                # need to dec frequency, and making cnt_lens[depth] to 0
                # no more prefix will have length >= depth, then answer is depth-1
                if cur.cnt==k and cnt_lens[depth]==1:
                    remain_max = depth - 1
                    break
            ans.append(remain_max)
        return ans
