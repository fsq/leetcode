class Solution {
public:
    
    void dfs(vector<vector<int>>& e, vector<vector<int>>& ans, vector<int>& vis, int x, int fa) {
        if (fa != x) ans[x].push_back(fa);
        vis[x] = true;
        for (auto y : e[x])
            if (!vis[y])
                dfs(e, ans, vis, y, fa);
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n), ans = e;
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
        }
        for (int i=0; i<n; ++i) {
            vector<int> vis(n);
            dfs(e, ans, vis, i, i);
        }
        return ans;
    }
};