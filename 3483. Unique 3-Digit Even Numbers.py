class Solution:
    def totalNumbers(self, a: List[int]) -> int:
        ans = set()
        for i in range(len(a)):
            for j in range(len(a)):
                for k in range(len(a)):
                    if i!=j and i!=k and j!=k and a[i]!=0 and a[k]%2==0:
                        ans.add(str(a[i])+str(a[j])+str(a[k]))
        return len(ans)
