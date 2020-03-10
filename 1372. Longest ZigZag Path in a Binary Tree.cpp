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
    pair<int,int> dfs(TreeNode* x) {
        if (!x) return {0, 0};
        auto fl=dfs(x->left), fr=dfs(x->right);
        pair<int,int> now{x->left ? fl.second+1 : 0, x->right ? fr.first+1 : 0};
        ans = max(ans, max(now.first, now.second));
        return now;
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};