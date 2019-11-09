class Solution {
public:
    int projectionArea(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> mr(n), mc(m);
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                mr[i] = max(mr[i], a[i][j]);
                mc[j] = max(mc[j], a[i][j]);
                ans += a[i][j] != 0;
            }
        return ans + accumulate(mr.begin(), mr.end(), 0) + accumulate(mc.begin(), mc.end(), 0);
    }
};