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
    vector<int> d, pre, lf;
    vector<vector<int>> e;
    
    int findn(TreeNode* x) {
        if (!x) return 0;
        return max(x->val, max(findn(x->left), findn(x->right)));
    }
    
    void dfs(TreeNode* x, int dpt) {
        d[x->val] = dpt;
        lf[x->val] = x->left ? x->left->val : 0;
        if (x->left) {
            dfs(x->left, dpt+1);
            e[x->left->val].push_back(x->val);
            e[x->val].push_back(x->left->val);
        }
        if (x->right) {        
            dfs(x->right, dpt+1);
            e[x->right->val].push_back(x->val);
            e[x->val].push_back(x->right->val);
        }
    }
    
    string getDirections(TreeNode* root, int start, int dest) {
        int n = findn(root);
        d.resize(n+1);
        pre.resize(n+1);
        lf.resize(n+1);
        e.resize(n+1);
        dfs(root, 0);
        queue<int> q;
        q.push(start);
        pre[start] = -1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto y : e[x])
                if (!pre[y]) {
                    pre[y] = x;
                    q.push(y);
                    if (y == dest) goto last;
                }
        }
        last:
        string ans;
        while (dest != start) {
            int p = pre[dest];
            if (d[dest] < d[p])
                ans.push_back('U');
            else if (lf[p] == dest)
                ans.push_back('L');
            else
                ans.push_back('R');
            dest = p;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};