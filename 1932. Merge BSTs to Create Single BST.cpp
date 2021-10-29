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
    
    int num_merge = 0;
    
    vector<int> build(TreeNode* x, unordered_map<int, TreeNode*>& tr) {
        vector<int> mnmx = {x->val, x->val, 1};
        if (x->left) {
            mnmx[0] = x->left->val;
            if (tr.count(x->left->val)) {
                auto ans = build(tr[x->left->val], tr);
                if (ans.empty() || ans[1] >= x->val) return {};
                x->left = tr[x->left->val];
                mnmx[0] = ans[0];
                ++num_merge;
            }
        }
        if (x->right) {
            mnmx[1] = x->right->val;
            if (tr.count(x->right->val)) {
                auto ans = build(tr[x->right->val], tr);
                if (ans.empty() || ans[0] <= x->val) return {};
                x->right = tr[x->right->val];
                mnmx[1] = ans[1];
                ++num_merge;
            }
        }
        return mnmx;
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, int> cnt;
        unordered_map<int, TreeNode*> tr;
        for (auto t : trees) {
            if (++cnt[t->val] > 2) return nullptr;
            if (t->left && ++cnt[t->left->val]>2) return nullptr;
            if (t->right && ++cnt[t->right->val]>2) return nullptr;
            tr[t->val] = t;
        }
        TreeNode* root;
        int rtcnt = 0;
        for (auto t : trees)
            if (cnt[t->val] == 1) {
                root = t;
                ++rtcnt;
            }
        if (rtcnt != 1) return nullptr;
        auto res = build(root, tr);
        if (res.empty() || num_merge!=trees.size()-1) return nullptr;
        return root;
    }
};