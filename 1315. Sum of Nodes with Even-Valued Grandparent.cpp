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
    
    void dfs(TreeNode* gf, TreeNode* f, TreeNode* x) {
        if (!x) return;
        if (gf && !(gf->val&1)) ans += x->val;
        dfs(f, x, x->left);
        dfs(f, x, x->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(nullptr, nullptr, root);
        return ans;
    }
};