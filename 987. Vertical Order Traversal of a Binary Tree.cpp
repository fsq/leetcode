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
    map<int, map<int, set<int>>> pos;
    
    void dfs(TreeNode* now, int x, int y) {
        if (!now) return;
        pos[x][y].insert(now->val);
        dfs(now->left, x-1, y-1);
        dfs(now->right, x+1, y-1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto& kv : pos) {
            vector<int> col;
            for (auto it=kv.second.rbegin(); it!=kv.second.rend(); ++it)
                col.insert(col.end(), it->second.begin(), it->second.end());
            ans.push_back(move(col));
        }
            
        
        return ans;
    }
};