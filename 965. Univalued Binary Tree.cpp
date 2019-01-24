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
    
    int target;
    bool ok = true;
    
    void dfs(TreeNode* x) {
        if (!x) return;
        if (x->val != target) {
            ok = false;
            return;
        }
        dfs(x->left);
        if (!ok) return;
        dfs(x->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        target = root->val;
        dfs(root);
        return ok;
    }
};