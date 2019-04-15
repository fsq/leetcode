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
    int ans = 0;
    
    void dfs(TreeNode* x, int mn, int mx) {
        if (!x) return;
        ans = max(ans, max(abs(mn-x->val), abs(mx-x->val)));
        mn = min(mn, x->val);
        mx = max(mx, x->val);
        dfs(x->left, mn, mx);
        dfs(x->right, mn, mx);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return ans;
    }
};