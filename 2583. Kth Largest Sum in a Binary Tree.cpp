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
    vector<long long> a;

    void dfs(TreeNode* t, int d) {
        if (a.size()==d) 
            a.push_back(t->val);
        else 
            a[d] += t->val;
        if (t->left) dfs(t->left, d+1);
        if (t->right) dfs(t->right, d+1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);        
        if (a.size()<k) return -1;
        nth_element(a.begin(),a.begin()+k-1, a.end(), std::greater<long long>());
        return a[k-1];
    }
};