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
    vector<vector<int>> a;
    int pos[100001];

    void dfs(TreeNode* x, int dp) {
        if (!x) return;
        if (a.size()==dp) a.push_back({});
        a[dp].push_back(x->val);
        dfs(x->left, dp+1);
        dfs(x->right, dp+1);
    }

    int solve(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        for (int i=0; i<b.size(); ++i) pos[b[i]] = i;

        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            if (b[i] > 0) { // not vis
                while (b[i] > 0) {
                    b[i] = -1;
                    ++ans;
                    i = pos[a[i]];
                }
                --ans;
            }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        dfs(root, 0);

        int ans = 0;
        for (auto& lv : a) ans += solve(lv);
        return ans;
    }
};