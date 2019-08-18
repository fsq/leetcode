# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
        
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def dfs(root: TreeNode):
            if not root:
                return -1, 0
            dl, ansl = dfs(root.left)
            dr, ansr = dfs(root.right)
            return max(dl,dr)+1, max(ansl, ansr, dl+dr+2)
        
        return dfs(root)[1]
        
        