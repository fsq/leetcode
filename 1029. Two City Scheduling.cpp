class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> f(n+1, 100000);
        f[0] = 0;
        for (int i=0; i<n; ++i) {
            for (int j=min(n/2, i+1); j>=0; --j)
                f[j] = min(f[j]+a[i][1], j>0 ? f[j-1]+a[i][0] : INT_MAX);
        }
        return f[n/2];
    }
};