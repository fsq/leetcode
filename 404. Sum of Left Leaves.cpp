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
    
    void dfs(TreeNode* x, int left) {
        if (!x) return;
        if (!x->left && !x->right) {
            if (left) ans += x->val;
        } else {
            dfs(x->left, true);
            dfs(x->right, false);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return ans;
    }
};