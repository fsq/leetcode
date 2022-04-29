class Solution {
public:
    
    int ans = 0;
    
    void dfs(vector<vector<vector<int>>>& e, vector<int>&values, vector<int>& d, vector<int>& vis,
             int x, int t, int val, const int maxTime) {
        if (t + d[x] > maxTime) return;
        bool take = false;
        if (!vis[x]) {
            take = true;
            vis[x] = true;
            val += values[x];    
        }
        if (x==0) ans = max(ans, val);
        for (auto& pr : e[x]) 
            if (t + pr[1] <= maxTime) {
                dfs(e, values, d, vis, pr[0], t+pr[1], val, maxTime);
            }
        
        if (take) {
            vis[x] = false;
        }
        return;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<int> d(n, INT_MAX), vis(n, false);
        vector<vector<vector<int>>> e(n);
        for (auto& edge : edges) {
            e[edge[0]].push_back({edge[1], edge[2]});
            e[edge[1]].push_back({edge[0], edge[2]});
        }
        d[0] = 0;
        for (int i=1; i<n; ++i) {
            int mind=INT_MAX, ind=-1;
            for (int j=0; j<n; ++j)
                if (!vis[j] && d[j]<mind) {
                    mind = d[j];
                    ind = j;
                }
            if (ind==-1) break;
            vis[ind] = true;
            for (auto& pr : e[ind])
                if (!vis[pr[0]] && d[pr[0]] > d[ind] + pr[1]) {
                    d[pr[0]] = d[ind] + pr[1];
                }
        }
        fill(vis.begin(), vis.end(), false);
        dfs(e, values, d, vis, 0, 0, 0, maxTime);
        return ans;
    }
};