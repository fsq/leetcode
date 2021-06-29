class Solution {
public:
    int n, ans = 1;
    
    int dfs(vector<vector<int>>& e, string& c, vector<vector<int>>& f, vector<int>& vis, int x) {
        vis[x] = 1;
        for (auto y : e[x]) {
            if (vis[y]==1) 
                return false;
            else if (vis[y]==0) {
                if (!dfs(e, c, f, vis, y)) return false;
            }
            for (int i=0; i<26; ++i) {
                f[x][i] = max(f[x][i], f[y][i]+(c[x]-'a'==i));
                ans = max(ans, f[x][i]);
            }
        }
        vis[x] = 2;
        return true;
    }
    
    int largestPathValue(string c, vector<vector<int>>& es) {
        n = c.size();
        vector<vector<int>> e(n), f(n, vector<int>(26));
        for (auto& pr : es) e[pr[0]].push_back(pr[1]);
        vector<int> vis(n);
        
        for (int i=0; i<n; ++i) f[i][c[i]-'a'] = 1;
        for (int i=0; i<n; ++i)
            if (!vis[i] && !dfs(e, c, f, vis, i)) {
                return -1;
            }
        return ans;
    }
};