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
    unordered_map<int, long long> m;

    void dfs(TreeNode* x, int dp) {
        if (!x) return;
        m[dp] += x->val;
        dfs(x->left, dp + 1);
        dfs(x->right, dp + 1);
    }

    int minimumLevel(TreeNode* root) {
        dfs(root, 1);
        int d = 0;
        long long mn = LLONG_MAX;
        for (auto& pr : m) 
            if (pr.second < mn || pr.second==mn && pr.first<d) {
                mn = pr.second;
                d = pr.first;
            }
        return d;
    }
};