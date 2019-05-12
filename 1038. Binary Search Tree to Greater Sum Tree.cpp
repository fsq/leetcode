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
    
    int tot = 0;
    
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return NULL;
        bstToGst(root->right);
        root->val = tot += root->val;
        bstToGst(root->left);
        return root;
    }
};