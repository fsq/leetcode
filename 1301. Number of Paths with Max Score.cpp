class Solution {
public:
    const int M = 1e9 + 7;
    
    vector<int> dx={0, 1, 1};
    vector<int> dy={1, 0, 1};
    
    vector<int> pathsWithMaxScore(vector<string>& a) {
        int n = a.size();
        vector<vector<pair<int,int>>> f(n, vector<pair<int,int>>(n));
        a[n-1][n-1] = '0';
        f[0][0] = {0, 1};
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (f[i][j].second)
                    for (int d=0; d<3; ++d) {
                        int tx=i+dx[d], ty=j+dy[d];
                        if (tx<n && ty<n &&a[tx][ty]!='X') {
                            if (f[i][j].first+a[tx][ty]-'0'>f[tx][ty].first)
                                f[tx][ty] = {f[i][j].first+a[tx][ty]-'0', f[i][j].second};
                            else if (f[i][j].first+a[tx][ty]-'0'==f[tx][ty].first)
                                f[tx][ty].second = (f[tx][ty].second + f[i][j].second) % M;
                        }
                    }
        return {f[n-1][n-1].first, f[n-1][n-1].second};
    }
};