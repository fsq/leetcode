class Solution {
public:
    
    const int INF = 0x3f3f3f3f;
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1);
        vector<vector<int>> d(n, vector<int>(n, INF));
        for (auto& pr :edges) {
            --pr[0], --pr[1];
            d[pr[0]][pr[1]] = d[pr[1]][pr[0]] = 1;
        }
        
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    if (i != j) 
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        for (int m=1; m<(1<<n); ++m) {
            if ( (m & (m-1)) == 0) continue;
            int mx = 0, cnt = 0, eg = 0;
            for (int i=0; i<n; ++i)
                if ((m>>i) & 1) {
                    ++cnt;
                    for (int j=i+1; j<n; ++j)
                        if ((m>>j) & 1) {
                            mx = max(mx, d[i][j]);
                            if (d[i][j]==1) ++eg;
                        }
                }
            if (eg + 1 != cnt) continue;
            ++ans[mx - 1];
        }
        return ans;
    }
};