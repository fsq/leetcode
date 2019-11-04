class Solution {
public:
    
    int mxdp = 0, ans = 0;
    
    void dfs(const vector<vector<int>>& e, vector<int>& vis, int x, int dp) {
        vis[x] = true;
        
        if (dp > mxdp) {
            mxdp = dp;
            ans = x;
        }
        for (auto y : e[x])
            if (!vis[y])
                dfs(e, vis, y, dp+1);
    }
    
    int treeDiameter(vector<vector<int>>& edge) {
        vector<vector<int>> e(edge.size() + 1);
        for (auto& eg : edge) {
            e[eg[0]].push_back(eg[1]);
            e[eg[1]].push_back(eg[0]);
        }
        vector<int> vis(e.size());
        dfs(e, vis, 0, 0);
        fill(vis.begin(), vis.end(), 0);
        dfs(e, vis, ans, 0);
        return mxdp;
    }
};