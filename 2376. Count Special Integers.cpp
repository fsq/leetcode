class Solution {
public:

    int ans = 0;
    vector<vector<int>> f;

    void dfs(string& s, vector<int>& vis, int i) {
        if (i==s.size()) {
            ++ans;
            return;
        } else {
            for (int x=i==0 ? 1 : 0; x<=s[i]-'0'; ++x)
                if (!vis[x]) {
                    if (x!=s[i]-'0') {
                        ans += f[s.size()-i-1][10-i-1];
                    } else {
                        vis[x] = true;
                        dfs(s, vis, i+1);
                    }
                }
        }
    }

    int countSpecialNumbers(int n) {
        string s = to_string(n);
        f = vector<vector<int>>(s.size(), vector<int>(11));
        fill(f[0].begin(), f[0].end(), 1);
        for (int i=1; i<s.size(); ++i) {
            f[i][0] = 1;
            for (int j=i; j<=10; ++j) {
                f[i][j] = j * f[i-1][j-1];
            }
        }
        vector<int> vis(10);
        for (int i=1; i<s.size(); ++i) ans += 9 * f[i-1][9];
        dfs(s, vis, 0);
        return ans;
    }
};