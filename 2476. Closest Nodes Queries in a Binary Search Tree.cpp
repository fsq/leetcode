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

    void dfs(TreeNode* x, set<int>& st) {
        if (!x) return;
        st.insert(x->val); 
        dfs(x->left, st);
        dfs(x->right, st);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        set<int> st;
        dfs(root, st);
        vector<vector<int>> ans;
        for (auto x : queries) {
            auto it = st.lower_bound(x);
            int mx = it==st.end() ? -1 : *it;
            int mn = 0;
            if (it==st.end())
                mn = st.size() == 1 ? -1 : *prev(it);
            else if (*it==x)
                mn = x;
            else 
                mn = it==st.begin() ? -1 : *prev(it);
            ans.push_back({mn, mx});
        }
        return ans;
    }
};