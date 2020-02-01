class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> d(n, vector<int>(n, INF));
        for (auto& e : edges) {
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
        }
        for (int i=0; i<n; ++i) d[i][i] = 0;
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    if (k!=i && k!=j)
                        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        int mn = INF, ans;
        for (int i=n-1; i>=0; --i) {
            int r = 0;
            for (int j=0; j<n; ++j)
                if (d[i][j] <= distanceThreshold)
                    ++r;
            if (r < mn) {
                mn = r;
                ans = i;
            }
        }
        return ans;
    }
};