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
    
    // https://leetcode.com/problems/binary-tree-upside-down/description/
    // O(n) time O(h) space
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        auto ret = upsideDownBinaryTree(root->left);
        root->left->right = root;
        root->left->left = root->right;
        root->left = root->right = NULL;
        return ret;
    }
};