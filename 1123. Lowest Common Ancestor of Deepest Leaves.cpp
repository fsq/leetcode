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
    
    pair<int,TreeNode*> dfs(TreeNode* x) {
        if (!x) return {-1, NULL};
        auto l = dfs(x->left);
        auto r = dfs(x->right);
        if (l.first == r.first)
            return {l.first+1, x};
        else if (l.first > r.first)
            return {l.first+1, l.second};
        else return {r.first+1, r.second};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};