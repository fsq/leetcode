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
    unordered_map<int, int> s;
    
    void dfs(TreeNode* x, int dp) {
        if (!x) return;
        s[dp] += x->val;
        dfs(x->left, dp+1);
        dfs(x->right, dp+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int dp, sum = INT_MIN;
        for (auto& kv : s)
            if (kv.second > sum || kv.second==sum && kv.first<dp) {
                dp = kv.first;
                sum = kv.second;
            }
        return dp;
    }
};