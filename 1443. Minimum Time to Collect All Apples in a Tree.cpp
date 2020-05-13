class Solution {
public:
    
    int ans = 0;
    bool dfs(vector<vector<int>>& e, vector<bool>& has, int x) {
        bool ap = false;
        for (auto y : e[x]) 
            ap |= dfs(e, has, y);
        if (ap || has[x]) {
            if (x>0) ans += 2;
            return true;
        } else
            return false;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> e(n+1);
        for (auto& p : edges) e[p[0]].push_back(p[1]);
        dfs(e, hasApple, 0);
        return ans;
    }
};