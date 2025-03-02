class Solution:
    def resultsArray(self, a: List[int], k: int) -> List[int]:
        ans = []
        inc = 0
        for r in range(len(a)):
            if r>0 and a[r]==a[r-1]+1:
                inc += 1
            if r >= k:
                l = r - k
                if a[l+1]==a[l]+1:
                    inc -= 1
            if r >= k-1:
                if inc == k-1:
                    ans.append(a[r])
                else:
                    ans.append(-1)
        return ans