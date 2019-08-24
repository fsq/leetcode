# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        d = dict()
        def dfs(x : TreeNode, dp : int):
            if not x: return
            d[dp] = d.get(dp, 0) + x.val
            dfs(x.left, dp+1)
            dfs(x.right, dp+1)
        dfs(root, 1)
        ans, tot = 0, -sys.maxsize
        for dp, s in d.items():
            if s>tot or s==tot and dp<ans:
                ans, tot = dp, s
        return ans
            