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
    
    pair<int,int> dfs(TreeNode* x) {
        if (!x) return {0, 0};
        auto l=dfs(x->left), r=dfs(x->right);
        return {max(l.first,l.second)+max(r.first,r.second), x->val+l.first+r.first};
    }
    
    int rob(TreeNode* root) {
        auto pr = dfs(root);
        return max(pr.first, pr.second);
    }
};