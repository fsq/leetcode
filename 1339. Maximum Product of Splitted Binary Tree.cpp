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
    
    long long sum = 0, ans = 0;
    
    long long dfs(TreeNode* x) {
        if (!x) return 0;
        return dfs(x->left)+dfs(x->right)+x->val;
    }
    
    long long dfs1(TreeNode* x) {
        if (!x) return 0;
        long long now = dfs1(x->left) + dfs1(x->right) + x->val;
        ans = max(ans, now * (sum-now));
        return now;
    }
    
    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        dfs1(root);
        return ans % 1000000007;
    }
};