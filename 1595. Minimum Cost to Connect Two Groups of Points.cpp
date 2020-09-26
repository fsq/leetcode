class Solution {
public:
    int ans = 0, n, m;
    int f[13][4100];
    int INF = 0x3f3f3f3f;
    
    int dp(vector<vector<int>>& a, int i, int y) {
        if (i==n && y==0) return 0;
        if (i==n || y==0) return INF;
        if (f[i][y] != -1) return f[i][y];
        int& ans = f[i][y];
        ans = INF;
        
        for (int j=0; j<m; ++j)
            if ((y>>j) & 1) {
                int f1 = dp(a, i+1, y), f2 = dp(a, i, y ^ (1<<j)), f3 = dp(a, i+1, y^(1<<j));
                ans = min(ans, min(min(f1, f2), f3) + a[i][j]);
            }
        return ans;
    }
    
    
    int connectTwoGroups(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        memset(f, -1, sizeof(f));
        return dp(a, 0, (1<<m)-1);
    }
};