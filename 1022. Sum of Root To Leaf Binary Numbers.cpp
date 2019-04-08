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
    
    void dfs(TreeNode* x, int pre, int& sum) {
        if (!x) return;
        pre = (pre<<1) | x->val;
        if (!x->left && !x->right)
            sum += pre;
        else {
            dfs(x->left, pre, sum);
            dfs(x->right, pre, sum);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};