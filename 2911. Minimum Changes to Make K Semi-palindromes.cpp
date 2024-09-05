class Solution {
public:
    int minimumChanges(string s, int k) {
        int g[201][201]; // g[i][j] = min#op to make i...j semi pan
        int f[201][201];
        
        int n = s.size();

        unordered_map<int, vector<int>> dv; // divisors of i, excluding i itself
        for (int i=1; i<=n; ++i)
            for (int j=1; j<i; ++j)
                if (i%j == 0)
                    dv[i].push_back(j);
        
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j) {
                g[i][j] = 0x3f3f3f3f;
                for (int d: dv[j-i+1]) {
                    int cur = 0;
                    int len = j - i + 1;
                    for (int l=0; l<len; ++l) {
                        int r = (len / d - 1 - l / d) * d + l % d;
                        if (l >= r)
                            break;
                        cur += (s[i + l] != s[i + r]);
                    }
                    g[i][j] = min(g[i][j], cur);
                }
            }
        
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=k; ++j) {
                for (int p=0; p<=i-2; ++p) {
                    f[i][j] = min(f[i][j], f[p][j-1] + g[p][i-1]);
                }
            }
        return f[n][k];


    }
};