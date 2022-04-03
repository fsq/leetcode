class Solution {
public:
    int n;
    vector<int> s;
    
    void dfs(vector<vector<int>>& e, int x) {
        s[x] = 1;
        for (auto y : e[x]) {
            dfs(e, y);
            s[x] += s[y];
        }
    }
    
    int countHighestScoreNodes(vector<int>& p) {
        n = p.size();
        vector<vector<int>> e(n);
        for (int i=1; i<n; ++i) e[p[i]].push_back(i);
        s.resize(n);
        
        dfs(e, 0);
        
        long long mx = -1;
        int ans = 0;
        
        for (int i=0; i<n; ++i) {
            long long pd = max(1, s[0] - s[i]);
            for (auto y : e[i])
                pd *= s[y];
            if (pd == mx)
                ++ans;
            else if (pd > mx) {
                mx = pd;
                ans = 1;
            }
        }
        return ans;
    }
};