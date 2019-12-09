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
    
    void dfs(TreeNode* x, vector<int>& a) {
        if (!x) return;
        if (!x->left && !x->right) {
            a.push_back(x->val);
        } else {
            dfs(x->left, a);
            dfs(x->right, a);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
};