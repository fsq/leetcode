class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n+1);
        for (auto& p : dependencies)
            pre[p[1]-1] |= 1 << (p[0]-1);
        
        vector<int> dep(1<<n);
        for (int i=1; i<(1<<n); ++i)
            for (int j=0; j<n; ++j)
                if (i & (1<<j))
                    dep[i] |= pre[j];

        vector<int> dp(1<<n, n+1);
        dp[0] = 0;
        // Iterate sub mask
        for (int m=1; m<(1<<n); ++m) {
            for (int s=m; s; s=m&(s-1)) 
                if (__builtin_popcount(s)<=k && ((m^s) & dep[s]) == dep[s])  
                    dp[m] = min(dp[m], dp[m^s]+1);
        }
        return dp.back();
    }
};