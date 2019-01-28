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
    int ans = 0;
    
    // #nodes #coins
    pair<int,int> dfs(TreeNode* x) {
        if (!x) return {0, 0};
        auto lf = dfs(x->left), rt = dfs(x->right);
        int n = lf.first+rt.first+1, c = lf.second+rt.second+x->val;
        ans += abs(n-c);
        return {n, c};
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};