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
    
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
    // LCA of a BST
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;
        if (root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
        
    }
};