class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size(), ans = 2;
        vector<unordered_map<int, int>> f(n+1);
        for (int i=n-1; i>=0; --i)
            for (int j=i+1; j<n; ++j) {
                int c = a[j] - a[i];
                if (f[j].count(c))
                    f[i][c] = max(f[i][c], 1 + f[j][c]);
                else 
                    f[i][c] = max(f[i][c], 2);
                ans = max(ans, f[i][c]);
            }
        return ans;
    }
};