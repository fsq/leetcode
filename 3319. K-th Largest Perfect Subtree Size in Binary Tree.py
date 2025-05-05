# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        sz = []
        def dfs(x):
            if not x:
                return 0
            l, r = dfs(x.left), dfs(x.right)
            if l==-1 or r==-1 or l!=r:
                return -1
            else:
                sz.append(l+r+1)
                return l+r+1

        dfs(root)
        return -1 if len(sz)<k else sorted(sz, reverse=True)[k-1]