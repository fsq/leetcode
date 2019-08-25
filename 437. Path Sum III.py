# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dfs(x: TreeNode, d: dict, s: int) -> int:
            if not x: 
                return 0
            s += x.val
            ans = d.get(s-sum, 0)
            d[s] = d.get(s, 0) + 1
            ans += dfs(x.left, d, s) + dfs(x.right, d, s)
            d[s] -= 1
            return ans
        d = dict()
        d[0] = 1
        return dfs(root, d, 0)
        
            