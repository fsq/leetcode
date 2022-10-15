class Solution {
public:
    int n, ans;
    vector<int> f;
    vector<vector<int>> e;
    string s;
    
    void dfs(int x) {
        f[x] = 1;
        int m1=0, m2=0;
        for (auto y : e[x]) {
            dfs(y);
            if (s[x] != s[y]) {
                if (f[y]>=m1) {
                    m2 = m1; m1 = f[y];
                } else if (f[y]>m2) {
                    m2 = f[y]; 
                }
            }
        }
        f[x] = 1 + m1;
        ans = max(ans, 1 + m1 + m2);
    }
    
    int longestPath(vector<int>& parent, string _s) {
        s = _s;
        n = s.size();
        e.resize(n);
        f.resize(n);
        for (int i=1; i<n; ++i)
            e[parent[i]].push_back(i);
        dfs(0);
        return ans;
    }
};