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
    int h[100001], f[100001];
    int n = 0;

    void dfs(TreeNode* x, int ht) {
        if (!x) return;
        ++n;
        h[x->val] = ht;
        if (x->left) {
            dfs(x->left, ht+1);
            h[x->val] = max(h[x->val], h[x->left->val]);
        }
        if (x->right) {
            dfs(x->right, ht+1);
            h[x->val] = max(h[x->val], h[x->right->val]);
        }
    }

    void solve(TreeNode* x, int mx, int ht) { // height of the tree other than subtree x.
        if (!x) return;
        f[x->val] = mx;
        solve(x->left, max(max(ht, mx), x->right ? h[x->right->val] : 0), ht+1);
        solve(x->right, max(max(ht, mx), x->left ? h[x->left->val] : 0), ht+1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        solve(root, 0, 0);
        vector<int> ans;
        for (auto x : queries) ans.push_back(f[x]);
        return ans;
    }
};