class Solution:
    def findDisappearedNumbers(self, a: List[int]) -> List[int]:
#         for i in range(len(a)):
#             while a[i]!=i+1 and a[a[i]-1]!=a[i]:
#                 x, y = i, a[i]-1
#                 a[x], a[y] = a[y], a[x]
    
#         return [i+1 for i,x in enumerate(a) if x!=i+1]
        
        s = set(a)
        return [x for x in range(1, len(a)+1) if x not in s]