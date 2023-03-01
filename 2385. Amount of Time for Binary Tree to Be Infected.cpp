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

    void dfs(TreeNode* x, unordered_map<int, vector<int>>& e) {
        if (x->left) {
            e[x->val].push_back(x->left->val);
            e[x->left->val].push_back(x->val);
            dfs(x->left, e);
        }
        if (x->right) {
            e[x->val].push_back(x->right->val);
            e[x->right->val].push_back(x->val);
            dfs(x->right, e);
        }
    }

    int d2(unordered_map<int, vector<int>>& e, int now, int pre=-1) {
        int mx = 0;
        for (auto y : e[now])
            if (y != pre) {
                mx = max(mx, d2(e, y, now)+1);
            }
        return mx;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> e;
        dfs(root, e);

        return d2(e, start);
    }
};