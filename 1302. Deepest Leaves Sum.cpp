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
    int dp = 0, sum = 0;
    
    void dfs(TreeNode* x, int d) {
        if (!x) return;
        if (d > dp) {
            dp = d;
            sum = x->val;
        } else if (d==dp) {
            sum += x->val;
        }
        dfs(x->left, d+1);
        dfs(x->right, d+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 1);
        return sum;
    }
};