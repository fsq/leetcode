/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* x, int mx) {
        if (!x) return;
        if (x->val >= mx) ++ans;
        mx = max(mx, x->val);
        dfs(x->left, mx);
        dfs(x->right, mx);
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, -100000);
        return ans;
    }
};