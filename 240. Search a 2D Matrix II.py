class Solution:
    def searchMatrix(self, a, tar):
        if len(a)==0 or len(a[0])==0:
            return False
        i, j = 0, len(a[0])-1
        while i < len(a):
            while a[i][j] > tar and j>0:
                j -= 1
            if a[i][j]==tar:
                return True
            i += 1
        return False
            
        