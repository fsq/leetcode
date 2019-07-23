class Solution {
public:
    
    vector<vector<pair<int,int>>> f;
        
    pair<int, int> dp(vector<int>& a, int i, int j) {
        if (i == j) return {0, a[i]};
        if (f[i][j].first) return f[i][j];
        int mx = -1;
        int ans = INT_MAX;
        for (int k=i; k<j; ++k) {
            auto l = dp(a, i, k);
            auto r = dp(a, k+1, j);
            mx = max(l.second, r.second);
            ans = min(ans, l.first + r.first + l.second*r.second);
        }
        return f[i][j] = {ans, mx};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        f = vector<vector<pair<int,int>>>(arr.size(), vector<pair<int,int>>(arr.size()));
        return dp(arr, 0, arr.size()-1).first;
    }
};