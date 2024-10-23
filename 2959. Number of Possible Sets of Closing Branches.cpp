class Solution {
public:
    int d[11][11];

    void floyd(int n, int m) {
        for (int i=0; i<n; ++i) d[i][i] = 0;
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    if ((m>>i & 1) && (m>>j & 1) && i!=j && d[i][k]+d[k][j]<d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
    }

    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;

        for (int i=0; i<(1<<n); ++i) {
            memset(d, 0x3f, sizeof(d));
            for (auto& r: roads)
                if ((i>>r[0] & 1) && (i>>r[1] & 1)) {
                    d[r[1]][r[0]] = d[r[0]][r[1]] = min(d[r[0]][r[1]], r[2]);
                }
            floyd(n, i);
            for (int x=0; x<n; ++x) 
                if (i>>x & 1) {
                    for (int y=0; y<n; ++y)
                        if ((i>>y & 1) && x!=y && d[x][y]>maxDistance)
                            goto last;
                }
            ++ans;
            last:
            continue;
        }
        return ans;
    }
};