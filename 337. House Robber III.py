# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        def dfs(x: TreeNode):
            if not x: return [0, 0]
            l, r = dfs(x.left), dfs(x.right)
            return [l[1]+r[1]+x.val, max(l)+max(r)]
        return max(dfs(root))
            