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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        while (q.size()) {
            vector<TreeNode*> a;
            for (int t=q.size(); t; --t) {
                auto x = q.front(); q.pop();
                if (x->left) {
                    a.push_back(x->left);
                    a.push_back(x->right);
                }
            }
            if (d & 1) {
                for (int l=0, r=a.size()-1; l<r; ++l, --r) {
                    swap(a[l]->val, a[r]->val);
                }
            }
            for (auto x : a) {
                q.push(x);
            }
            ++d;
        }
        return root;
    }
};