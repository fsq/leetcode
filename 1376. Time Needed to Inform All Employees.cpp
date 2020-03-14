class Solution {
public:
    
    int dfs(int x, vector<vector<int>>& e, vector<int>& cost) {
        int mx = 0;
        for (auto y : e[x])
            mx = max(mx, dfs(y, e, cost));
        return mx + cost[x];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> e(n);
        for (int i=0; i<n; ++i)
            if (manager[i]!=-1)
                e[manager[i]].push_back(i);
        return dfs(headID, e, informTime);
    }
};