class Solution {
public:
    
    int minimumDistance(string s) {
        int n = s.size();
        auto dist = [&](char a, char b) {
            int x=a-'A', y=b-'A';
            return abs(x/6-y/6) + abs(x%6-y%6);
        };
        vector<vector<int>> f(n+1, vector<int>(n+1, INT_MAX));
        f[0][1] = 0;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                if (f[i][j] != INT_MAX) {
                    f[i][j+1] = min(f[i][j+1], f[i][j] + dist(s[j-1], s[j]));
                    f[j][j+1] = min(f[j][j+1], f[i][j] + (i==0 ? 0 : dist(s[i-1], s[j])));
                }
        int ans = INT_MAX;
        for (int i=0; i<n; ++i)
            ans = min(ans, f[i][n]);
        return ans;
    }
};