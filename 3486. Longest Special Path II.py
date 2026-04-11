class Solution:
    def longestSpecialPath(self, edges: List[List[int]], nums: List[int]) -> List[int]:
        e = [[] for _ in range(len(nums))]
        for u, v, l in edges:
            e[u].append((v, l))
            e[v].append((u, l))

        ans = [0, 0]
        # pref: prefix sum array along path
        # path_start: current valid pref is pref[path_start+1:-1]
        # path_anc: depth of nearst ancestor of nums along current pref
        # dupped: -1 if no dup in current valid path; otherwise is the depth of the first dup
        def dfs(x, pref, path_start, path_anc, dupped=-1, dep=1, parent=-1):
            nonlocal ans

            prev_anc = path_anc[nums[x]]
            path_anc[nums[x]] = dep

            tot = pref[-1] - pref[path_start]
            if tot > ans[0] or (tot==ans[0] and len(pref)-path_start < ans[1]):
                ans = [tot, len(pref)-path_start]

            # Extend current path
            for y, l in e[x]:
                if y == parent:
                    continue

                next_dupped = dupped
                next_path_start = path_start
                # If adding y introduce another dup, we want to remove current dup
                # either remove last nums[y], or remove duppped, by shrinking path_start
                if next_dupped!=-1 and path_anc[nums[y]] > next_path_start:
                    next_path_start = min(path_anc[nums[y]], dupped)
                # If nums[y] is dupped in current valid path, update dupped
                if path_anc[nums[y]] > next_path_start:
                    next_dupped = path_anc[nums[y]]

                pref.append(pref[-1]+l)
                dfs(y, pref, next_path_start, path_anc, next_dupped, dep+1, x)
                pref.pop()

            path_anc[nums[x]] = prev_anc

        dfs(0, [0], 0, defaultdict(lambda: -1))

        return ans
