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
    // https://leetcode.com/problems/boundary-of-binary-tree/description/
    // tree traversal
    // O(n) time O(h) space
    
    vector<int> ans;
    
    void dfs(TreeNode* x, bool lb, bool rb) {
        if (!x) return;
        
        if (lb) ans.push_back(x->val);
        if (x->left) {
            dfs(x->left, lb, x->right ? false:rb);
            dfs(x->right, false, rb);
        } else 
            dfs(x->right, lb, rb);
        
        if (!lb && !rb && !x->left && !x->right)
            ans.push_back(x->val);
        
        if (rb) ans.push_back(x->val);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        
        ans.push_back(root->val);
        dfs(root->left, true, false);
        dfs(root->right, false, true);
        
        return ans;
    }
};