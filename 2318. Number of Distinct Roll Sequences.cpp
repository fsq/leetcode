class Solution {
public:

    int M = 1000000007;
    long long f[10001][7][7];

    int distinctSequences(int n) {
        if (n==1) return 6;
        memset(f, 0, sizeof(f));
        vector<vector<int>> pr;
        for (int x=1; x<=6; ++x)
            for (int y=1; y<=6; ++y)
                if (x!=y && __gcd(x, y) == 1) {
                    pr.push_back({x, y});
                    f[2][x][y] = 1;                    
                }
        
        for (int i=3; i<=n; ++i)
            for (int x=1; x<=6; ++x)
                for (auto& p: pr)
                    if (__gcd(x, p[1])==1 && x!=p[0])
                        f[i][p[1]][x] = (f[i][p[1]][x] + f[i-1][p[0]][p[1]]) % M;
        
        int ans = 0;
        for (auto& p : pr)
            ans = (ans + f[n][p[0]][p[1]]) % M;
        return ans;
    }
};