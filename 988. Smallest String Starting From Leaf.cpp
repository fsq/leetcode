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
    
    string dfs(TreeNode* x) {
        if (!x) return "";
        string l = dfs(x->left), r = dfs(x->right);
        string now = l.empty() ? r : (r.empty() ? l : min(l, r));
        return now+string(1, x->val+'a');
    }
    
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root);
    }
};