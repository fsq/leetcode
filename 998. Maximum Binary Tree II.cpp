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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root || val > root->val) {
            TreeNode* rt = new TreeNode(val);
            rt->left = root;
            return rt;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};