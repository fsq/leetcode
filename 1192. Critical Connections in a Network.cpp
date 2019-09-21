class Solution {
public:
    
    vector<int> d;
    vector<vector<int>> e, ans;
    
    int dfs(int x, int fa, int dp) {
        d[x] = dp;
        int lo = dp;
        for (auto y : e[x]) 
            if (y != fa) {
                if (!d[y]) {
                    int s = dfs(y, x, dp+1);
                    if (s > dp)
                        ans.push_back({x, y});
                    lo = min(lo, s);
                } else 
                    lo = min(lo, d[y]);
            }
        return lo;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& a) {
        d.resize(n);
        e.resize(n);
        for (auto& p : a) {
            e[p[1]].push_back(p[0]);
            e[p[0]].push_back(p[1]);
        }
        for (int i=0; i<n; ++i)
            if (!d[i]) 
                dfs(i, -1, 1);
        return ans;
    }
};