class Solution {
public:
    int f[1001][1001];

    int minOperations(string s, string t) {
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            for (int j=0; j<t.size(); ++j) {
                if (s[i] == t[j]) {
                    f[i][j] = (i>0 && j>0 ? f[i-1][j-1] : 0) + 1;
                    ans = max(ans, f[i][j]); 
                }
            }
        return s.size() - ans + (t.size() - ans);
    }
};