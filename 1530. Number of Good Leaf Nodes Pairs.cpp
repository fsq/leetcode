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
    
    int ans = 0, d;
    
    vector<int> dfs(TreeNode* x) {
        vector<int> ret(d+1);
        if (!x) return ret;
        if (!x->left && !x->right) {
            ret[1] = 1;
            return ret;
        }
        
        auto l = dfs(x->left), r = dfs(x->right);
        for (int s=0, dr=1; dr<d; ++dr) {
            s += r[dr];
            ans += l[d-dr] * s;
        }
        for (int i=2; i<ret.size(); ++i)
            ret[i] = l[i-1] + r[i-1];
        return ret;
    }
    
    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root);
        return ans;
    }
};