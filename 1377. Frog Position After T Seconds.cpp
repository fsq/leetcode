class Solution {
public:
    vector<int> fa, son;
    vector<vector<int>> e;
    
    void dfs(int x, int f) {
        fa[x] = f;
        son[x] = e[x].size() - (f != 0);
        for (auto y : e[x])
            if (y != f)
                dfs(y, x);
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        fa.resize(n+1);
        son.resize(n+1);
        e.resize(n+1);
        for (auto& p : edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        dfs(1, 0);
        
        int d = 0;
        for (int x=target; fa[x]; x=fa[x]) ++d;
        if (t < d || t>d && son[target]) return 0;
        
        double ans = 1;
        for (int x=target; fa[x]; x=fa[x]) ans *= 1.0 / son[fa[x]];
        return ans;
    }
};