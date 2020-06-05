class Solution {
public:
    
    int dfs(vector<vector<pair<int,int>>>& e, int x, int pre) {
        int ans = 0;
        for (auto& p : e[x])
            if (p.first != pre) 
                ans += p.second + dfs(e, p.first, x);
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& cn) {
        vector<vector<pair<int,int>>> e(n);
        for (auto& p : cn) {
            e[p[0]].push_back({p[1], 1});
            e[p[1]].push_back({p[0], 0});
        }
        return dfs(e, 0, 0);
    }
};