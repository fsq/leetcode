class Solution:
    def maxSubarrays(self, n: int, pr: List[List[int]]) -> int:
        for i, (x, y) in enumerate(pr):
            if x > y:
                pr[i] = (y, x)

        # pr indices left point at i
        pr_start = [[] for _ in range(n+1)]
        for i, p in enumerate(pr):
            pr_start[p[0]].append(i)
        
        tot_arr = 0  # tot valid subarray, without removing
        j = 1   # right boundary
        skipped = -1  # pr index that is skipped
        current_right = defaultdict(set) # pr indices list with right point at key, left point within window
        incre = [0] * len(pr) # increment of ans if remove pr[i]
        for i in range(1, n+1):
            # extend
            while j <= n:
                # how many pairs must be skipped if pick j
                if_pick = len(current_right.get(j, [])) + int(skipped!=-1)
                if if_pick > 1:
                    break
                
                # pick j
                if skipped==-1 and if_pick==1:
                    skipped = next(iter(current_right.get(j)))
                for pi in pr_start[j]:
                    current_right[pr[pi][1]].add(pi)

                j += 1
            
            # calculate ans
            if skipped != -1:
                tot_arr += pr[skipped][1] - i
                incre[skipped] += j - pr[skipped][1]
            else:
                tot_arr += j - i

            # advance
            for pi in pr_start[i]:
                current_right[pr[pi][1]].remove(pi)
                # reset skipped
                if pi == skipped:
                    skipped = -1

        return tot_arr + max(incre)

    def maxSubarraysReverseSlidingWindow(self, n: int, pr: List[List[int]]) -> int:
        # pr indices left point at i
        pr_start = [[] for _ in range(n+1)]
        for p in pr:
            pr_start[min(p)].append(max(p))
        
        tot_arr = 0  # tot valid subarray, without removing
        right = [n+1, n+1] # two closest right point, left point in [i, n]
        incre = [0] * (n + 2)
        for i in reversed(range(1, n+1)):
            for r in pr_start[i]:
                right = min(right, [r, right[0]], [right[0], r])
            tot_arr += right[0] - i
            incre[right[0]] += right[1] - right[0]

        return tot_arr + max(incre)
