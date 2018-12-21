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
    
    int maxid=0, cnt=0;
    
    void dfs(TreeNode* x, int id) {
        if (!x) return;
        ++cnt;
        maxid = max(maxid, id);
        dfs(x->left, id << 1);
        dfs(x->right, id << 1 | 1);
    }
    
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 1);
        return maxid == cnt;
    }
};