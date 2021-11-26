class Solution {
public:
    
    const int M = 1000000007;
    
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> e(n);
        for (const auto& p : edges) {
            e[p[0]].push_back({p[1], p[2]});
            e[p[1]].push_back({p[0], p[2]});
        }
        vector<long long> d(n, LLONG_MAX), way(n), vis(n);
        d[0] = 0; 
        way[0] = 1;
        for (int i=1; i<=n; ++i) {
            int p=-1;
            long long md = LLONG_MAX;
            for (int i=0; i<n; ++i)
                if (!vis[i] && d[i]<md) {
                    md = d[i];
                    p = i;
                }
            vis[p] = true;
            for (auto& pr : e[p]) 
                if (!vis[pr.first] && d[p]+pr.second<d[pr.first]) {
                    d[pr.first] = d[p] + pr.second;
                    way[pr.first] = way[p];
                } else if (d[p]+pr.second == d[pr.first]) {
                    way[pr.first] = (way[pr.first] + way[p]) % M;
                }
        }
        return way[n-1] % M;
    }
};