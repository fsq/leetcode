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
    // https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
    // inorder traversal O(n) time O(h) space (recursion)
    // inorder traversal gives an monotonically non-decreasing sequence
    
    vector<int> ret;
    int max_freq, pre, count;
    
    void dfs(TreeNode* node) {
        if (node->left) dfs(node->left);
        
        if (count==0 || node->val!=pre) {
            count = 1;
            pre = node->val;
        } else 
            ++count;
        
        if (count>max_freq) {
            max_freq = count;
            if (ret!=vector<int>{node->val})
                ret = {node->val};
        } else if (count==max_freq) 
            ret.push_back(node->val);
        
        if (node->right) dfs(node->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        max_freq = pre = count = 0;
        dfs(root);
        return ret;
    }
};