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
    
    TreeNode* build(const vector<int>& a, int fa, int& i) {
        if (i==a.size()) return NULL;
        TreeNode* root = new TreeNode(a[i++]);
        if (i!=a.size() && a[i]<root->val) 
            root->left = build(a, root->val, i);
        if (i!=a.size() && a[i]<fa)
            root->right = build(a, fa, i);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, INT_MAX, i);
    }
};