class Solution {
public:
    int extra = 0;

    void dfs(vector<vector<int>>& e, vector<int>& vis, int x, int fa) {
        vis[x] = 1;
        for (auto y : e[x])
            if (!vis[y])
                dfs(e, vis, y, x);
            else if (vis[y]==1 && y!=fa)
                ++extra;
        vis[x] = 2;
    }
    
    int makeConnected(int n, vector<vector<int>>& ed) {
        vector<vector<int>> e(n);
        for (auto& pr : ed) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        int cc = 0;
        vector<int> vis(n);
        for (int i=0; i<n; ++i)
            if (!vis[i]) {
                dfs(e, vis, i, -1);
                ++cc;
            }
        return cc<=extra+1 ? cc-1 : -1;
    }
};