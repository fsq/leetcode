class Solution {
public:
    
    vector<int> dx = {0, 0, 0, 1, -1};
    vector<int> dy = {0, 1, -1, 0, 0};
    vector<vector<int>> d;
    vector<pair<int,int>> pre, now;
    int stp = 0, n, m;
    
    void dfs(vector<vector<int>>& a, int x, int y) {
        if (x>=0 && x<n && y>=0 && y<m && d[x][y]==INT_MAX) {
            d[x][y] = stp;
            now.push_back({x, y});
            dfs(a, x+dx[a[x][y]], y+dy[a[x][y]]);
        }        
    }
    
    int minCost(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        d = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        
        dfs(a, 0, 0);
        while (now.size()) {
            ++stp;
            pre.swap(now);
            now.clear();
            for (auto& p : pre)
                for (int dir=1; dir<=4; ++dir) 
                    dfs(a, p.first+dx[dir], p.second+dy[dir]);
        }
        return d[n-1][m-1];
    }
};