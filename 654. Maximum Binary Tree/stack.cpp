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
    
    // https://leetcode.com/problems/maximum-binary-tree/description/
    // O(n) stack 
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = new TreeNode(INT_MAX);
        stack<TreeNode*> stk;
        stk.push(root);
        
        for (auto x : nums) {
            while (x>stk.top()->val) stk.pop();
            TreeNode *nxt = new TreeNode(x);
            nxt->left = stk.top()->right;
            stk.top()->right = nxt;
            stk.push(nxt);
        }
        
        auto ret = root->right;
        delete root;
        return ret;
    }
};