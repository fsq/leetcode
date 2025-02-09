class Solution:
    def countSubarrays(self, a: List[int], k: int) -> int:
        cur = [0 for i in range(30)]
        ans = 0
        for ind, x in enumerate(a):
            longest_k = ind + 1
            longest_nk = 0
            for i in range(30):
                if x >> i & 1:
                    cur[i] = cur[i] + 1
                else:
                    cur[i] = 0
                # Find min length where all bits in k are 1
                if k >> i & 1:
                    longest_k = min(longest_k, cur[i])
                # Find max length where all bits not in k are 1
                else:
                    longest_nk = max(longest_nk, cur[i])
            # indices between will have all k's bits=1, and non k's bit=0
            if longest_k >= longest_nk+1:
                ans += longest_k - longest_nk
        return ans