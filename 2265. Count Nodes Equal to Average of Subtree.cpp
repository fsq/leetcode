/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    vector<int> dfs(TreeNode* t) {
        if (t==nullptr) {
            return {0, 0};
        }
        vector<int> s = {t->val, 1};
        auto sl=dfs(t->left), sr=dfs(t->right);
        s[0] += sl[0] + sr[0];
        s[1] += sl[1] + sr[1];
        if (t->val == s[0] / s[1]) ++ans;
        return s;
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};