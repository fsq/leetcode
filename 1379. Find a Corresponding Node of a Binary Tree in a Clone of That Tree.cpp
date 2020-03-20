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
    TreeNode* ans = nullptr;
    
    void dfs(TreeNode* a, TreeNode* b, TreeNode* target) {
        if (!a) return;
        if (a==target) {
            ans = b;
            return;
        } else {
            dfs(a->left, b->left, target);
            if (ans) return;
            dfs(a->right, b->right, target);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* a, TreeNode* b, TreeNode* target) {
        dfs(a, b, target);
        return ans;
    }
};