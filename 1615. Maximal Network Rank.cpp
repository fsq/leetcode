class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& eg) {
        vector<int> d(n);
        vector<vector<int>> lap(n, vector<int>(n));
        for (auto& e : eg) {
            ++d[e[0]];
            ++d[e[1]];
            ++lap[e[0]][e[1]];
            ++lap[e[1]][e[0]];
        }
        
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j) 
                ans = max(ans, d[i]+d[j] - lap[i][j]);
        
        return ans;
    }
};