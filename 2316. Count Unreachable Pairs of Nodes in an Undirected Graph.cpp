class Solution {
public:

    long long dfs(vector<vector<int>>& e, vector<int>& vis, int x) {
        vis[x] = true;
        long long ans = 1;
        for (auto y : e[x])
            if (!vis[y]) 
                ans += dfs(e, vis, y);
        return ans;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<vector<int>> e(n);
        vector<int> vis(n);
        for (auto& p : edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        for (int i=0; i<n; ++i)
            if (!vis[i]) {
                long long t = dfs(e, vis, i);
                ans += t * (n - t);
            }
        return ans / 2;
    }
};