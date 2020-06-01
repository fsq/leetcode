class Solution {
public:
    
    void dfs(vector<vector<int>>& e, vector<int>& vis, vector<int>& lk, int x) {
        vis[x] = lk[x] = true;
        for (auto y : e[x]) if (!vis[y]) dfs(e, vis, lk, y);
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& ee, vector<vector<int>>& qr) {
        vector<vector<int>> lk(n, vector<int>(n));
        vector<vector<int>> e(n);
        for (auto& p : ee)
            e[p[0]].push_back(p[1]);
        for (int i=0; i<n; ++i) {
            vector<int> vis(n);
            dfs(e, vis, lk[i], i);
        }
        vector<bool> ans;
        for (auto& q: qr) 
            ans.push_back(lk[q[0]][q[1]]);
        return ans;
    }
};