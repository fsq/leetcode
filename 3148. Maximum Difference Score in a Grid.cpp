class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        int ans = -1000000;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j) {
                int mn = 1000000;
                if (i > 0) mn = min(mn, a[i-1][j]);
                if (j > 0) mn = min(mn, a[i][j-1]);
                if (i>0 && j>0) mn = min(mn, a[i-1][j-1]);
                ans = max(ans, a[i][j] - mn);
                a[i][j] = min(a[i][j], mn);
            }
        return ans;
    }
};