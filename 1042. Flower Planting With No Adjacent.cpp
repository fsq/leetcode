class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& eg) {
        vector<int> f(n+1);
        vector<vector<int>> e(n+1);
        for (auto& g : eg) {
            e[g[0]].push_back(g[1]);
            e[g[1]].push_back(g[0]);
        }
        
        for (int x=1; x<=n; ++x) {
            vector<int> vis(5);
            for (auto y : e[x])
                vis[f[y]] = true;

            for (int i=1; i<=4; ++i)
                if (!vis[i]) {
                    f[x] = i;
                    break;
                }
        }
           
        
        f.erase(f.begin());
        return f;
    }
};