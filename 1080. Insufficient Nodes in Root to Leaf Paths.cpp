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
    
    int dfs(TreeNode* x, int limit) {
        if (!x) return INT_MIN;
        if (!x->left && !x->right) return x->val;
        limit -= x->val;
        auto l = dfs(x->left, limit);
        if (l < limit) x->left = NULL;
        auto r = dfs(x->right, limit);
        if (r < limit) x->right = NULL;
        return max(l, r) + x->val;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int x = dfs(root, limit);
        if (x < limit) return NULL;
        return root;
    }
};