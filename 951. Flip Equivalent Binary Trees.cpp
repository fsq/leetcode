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
    bool flipEquiv(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->val==b->val) && 
            (flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right) ||
             flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left));
    }
};