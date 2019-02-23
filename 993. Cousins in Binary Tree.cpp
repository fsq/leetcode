/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int px, py, dx, dy;
    int x, y;
    
    void dfs(TreeNode* n, int dp, int fa) {
        if (!n) return;
        if (n->val==x) {
            px = fa;
            dx = dp;
        }
        if (n->val==y) {
            py = fa;
            dy = dp;
        }
        
        dfs(n->left, dp+1, n->val);
        dfs(n->right, dp+1, n->val);
    }
    
    bool isCousins(TreeNode* root, int _x, int _y) {
        x = _x, y = _y;
        dfs(root, 0, -1);
        return dx==dy && px!=py;
    }
};