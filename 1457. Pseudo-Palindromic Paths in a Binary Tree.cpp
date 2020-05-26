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
    
    void dfs(TreeNode* x, vector<int>& cnt) {
        if (!x) return;
        ++cnt[x->val];
        if (!x->left && !x->right) {
            int odd = count_if(cnt.begin(), cnt.end(), [](int x) { return x & 1; });
            if (odd<=1) ++ans;
        } else {
            dfs(x->left, cnt);
            dfs(x->right, cnt);
        }
        --cnt[x->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10);
        dfs(root, cnt);
        return ans;
    }
};