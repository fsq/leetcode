class Solution {
public:
    int n;

    void dfs(vector<vector<int>>& e, vector<int>& g, vector<int>& vis, int x) {
        vis[x] = true;
        g.push_back(x);
        for (auto y : e[x])
            if (!vis[y]) 
                dfs(e, g, vis, y);
    }

    int bfs(vector<vector<int>>& e, int x) {
        vector<int> d(n+1);
        queue<int> q;
        q.push(x);
        d[x] = 1;
        int ans = 1;
        while (q.size()) {
            auto x = q.front(); q.pop();
            for (auto y : e[x])
                if (!d[y]) {
                    ans = max(ans, d[y] = d[x] + 1);
                    q.push(y);
                } else if (d[y] == d[x]) 
                    return -1;
        }
        return ans;
    }

    int magnificentSets(int _n, vector<vector<int>>& edges) {
        n = _n;
        vector<vector<int>> e(n+1, vector<int>());
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }

        vector<int> vis(n+1);
        int ans = 0;
        for (int i=1; i<=n; ++i)
            if (!vis[i]) {
                vector<int> g;
                dfs(e, g, vis, i);
                int mx = 0;
                for (auto x : g) {
                    int dv = bfs(e, x);
                    if (dv == -1) return -1;
                    mx = max(mx, dv);
                }
                ans += mx;
            }
        return ans;
    }
};