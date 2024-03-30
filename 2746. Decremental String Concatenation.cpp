class Solution {
public:
    int f[1001][26][26];

    int minimizeConcatenatedLength(vector<string>& a) {
        int n = a.size();
        memset(f, 0x3f, sizeof(f));
        f[0][a[0].front()-'a'][a[0].back()-'a'] = a[0].size();
        for (int i=0; i+1<n; ++i) {
            int x=a[i+1].front()-'a', y=a[i+1].back()-'a', len=a[i+1].size();
            for (int c=0; c<26; ++c)
                for (int d=0; d<26; ++d) {
                    if (f[i][c][d] == 0x3f3f3f3f) continue;
                    f[i+1][x][d] = min(f[i+1][x][d], f[i][c][d] + len - (y==c));
                    f[i+1][c][y] = min(f[i+1][c][y], f[i][c][d] + len - (x==d));
                }
        }
        int ans = INT_MAX;
        for (int c=0; c<26; ++c)
            for (int d=0; d<26; ++d) {
                if (f[n-1][c][d] == 0x3f3f3f3f) continue;
                ans = min(ans, f[n-1][c][d]);
            }
        return ans;
    }
};