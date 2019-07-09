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
    vector<TreeNode*> ans;
    
    TreeNode* dfs(TreeNode* x, unordered_set<int>& st, bool root) {
        if (!x) return NULL;
        bool del = st.count(x->val);
        if (root && !del)
            ans.push_back(x);
        x->left = dfs(x->left, st, del);
        x->right = dfs(x->right, st, del);
        return del ? NULL : x;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        dfs(root, del, true);
        return ans;
    }
};