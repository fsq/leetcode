class Solution {
public:
    
    const int M = 1000000007;
    
    bool ok(vector<int>& s, int i, int j) {
        int x = s[i], y = s[j];
        while (x) {
            if (x % 10 == y % 10) return false;
            x /= 10;
            y /= 10;
        }
        return true;
    }
    
    void dfs(vector<int>& ans, string& s, int n, int i) {
        if (i==n) {
            ans.push_back(stoi(s));
        } else {
            for (int c='1'; c<='3'; ++c)
                if (c != s.back()) {
                    s.push_back(c);
                    dfs(ans, s, n, i+1);
                    s.pop_back();
                }
        }
    }
    
    vector<int> genlist(int n) {
        vector<int> ans;
        string s;
        dfs(ans, s, n, 0);
        return ans;
    }
   
    
    int colorTheGrid(int m, int n) {
        vector<int> list = genlist(m);
        vector<vector<int>> f(n, vector<int>(list.size()));
        fill(f[0].begin(), f[0].end(), 1);
        for (int i=1; i<n; ++i)
            for (int x=0; x<list.size(); ++x)
                for (int y=0; y<list.size(); ++y)
                    if (ok(list, x, y))
                        f[i][x] = (f[i][x] + f[i-1][y]) % M;
        int ans = 0;
        for (int i=0; i<list.size(); ++i)
            ans = (ans + f[n-1][i]) % M;
        return ans;
    }
};