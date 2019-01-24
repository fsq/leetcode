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
    vector<vector<int>> f;
    int n;
    const int INF = 100000000;
    
    void _mark(TreeNode* x, int& id) {
        if (!x) return;
        x->val = id;
        ++id, ++n;
        _mark(x->left, id);
        _mark(x->right, id);
    }
    
    void mark(TreeNode* x) {
        int id = 1;
        n = 0;
        _mark(x, id);
    }
    
    void dp(TreeNode* node) {
        if (!node) return;
        int x = node->val;
        dp(node->left);
        dp(node->right);
        
        int lf = node->left ? node->left->val : 0, rt = node->right ? node->right->val : 0;
        
        f[x][1] = f[x][2] = 1 + f[lf][2] + f[rt][2];
        f[x][2] = min(f[x][2], min(f[lf][0], f[lf][1])+min(f[rt][0], f[rt][1]));
        f[x][0] = min(f[lf][1]+f[rt][0], min(f[lf][0]+f[rt][1], f[lf][1]+f[rt][1]));
    }
    
    int minCameraCover(TreeNode* root) {
        mark(root);
        f = vector<vector<int>>(n+1, vector<int>(3, INF));
        f[0][0] = f[0][2] = 0; 
        
        dp(root);
        return min(f[1][0], f[1][1]);
    }
};