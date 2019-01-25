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
    vector<int> ans;
    
    void dfs(TreeNode* x, const vector<int>& vo, int& i) {
        if (!x) return;
        if (i==vo.size() || x->val != vo[i]) {
            ans = {-1};
            return;
        }
        ++i;
        if (i==vo.size()) return;
        
        if (x->left && x->left->val==vo[i]) {
            dfs(x->left, vo, i);
            if (ans==vector<int>{-1}) return;
            dfs(x->right, vo, i);
        } else if (x->right && x->right->val==vo[i] ){
            if (x->left) ans.push_back(x->val);
            dfs(x->right, vo, i);
            if (ans==vector<int>{-1}) return;
            dfs(x->left, vo, i);
        } else if (x->left || x->right)
            ans = {-1};
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        dfs(root, voyage, i);
        if (i!=voyage.size()) ans = {-1};
        return ans;
    }
};