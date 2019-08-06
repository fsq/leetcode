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
    
    int nl=0, nr=0, tar;
    
    void dfs(TreeNode* x, bool lf, bool rt) {
        if (!x) return;
        if (lf) ++nl;
        if (rt) ++nr;
        if (x->val == tar) {
            dfs(x->left, true, false);
            dfs(x->right, false, true);
        } else {
            dfs(x->left, lf, rt);
            dfs(x->right, lf, rt);
        }
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        tar = x;
        dfs(root, false, false);
        return n-nl-nr-1 > nl+nr+1 || nl > n-nl || nr>n-nr;
    }
};