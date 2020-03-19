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
    vector<int> a;
    void dfs(TreeNode* x) {
        if (!x) return;
        dfs(x->left);
        a.push_back(x->val);
        dfs(x->right);
    }
    
    TreeNode* build(int l, int r) {
        if (l > r) return NULL;
        int m = (l+r) >> 1;
        TreeNode* root = new TreeNode(a[m]);
        root->left = build(l, m-1);
        root->right = build(m+1, r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, a.size()-1);
    }
};