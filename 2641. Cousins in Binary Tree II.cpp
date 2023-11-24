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
    vector<int> level;
    unordered_map<TreeNode*, int> m;

    void dfs(TreeNode* x, int d, TreeNode* fa) {
        if (!x) return;
        if (level.size()==d) level.push_back(0);
        level[d] += x->val;
        if (fa) {
            m[x] = (fa->left ? fa->left->val : 0) + (fa->right ? fa->right->val : 0);
        }
        dfs(x->left, d+1, x);
        dfs(x->right, d+1, x);
    }

    void calc(TreeNode* x, int d, TreeNode* fa) {
        if (!x) return;
        calc(x->right, d+1, x);
        calc(x->left, d+1, x);
        if (fa) {
            x->val = level[d] - m[x];
        } else 
            x->val = 0;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root, 0, nullptr);    
        calc(root, 0, nullptr);
        return root;
    }
};