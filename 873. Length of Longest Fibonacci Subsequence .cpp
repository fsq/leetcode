class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> p;
        for (int i=0; i<n; ++i) p[a[i]] = i;
        
        int ans = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i=1; i<n; ++i)
            for (int j=0; j<i; ++j) {
                if (a[i]-a[j] < a[j] && p.count(a[i]-a[j]))
                    f[i][j] = f[j][p[a[i]-a[j]]] + 1;
                else
                    f[i][j] = 2;
                ans = max(ans, f[i][j]);
            }
        return ans>2 ? ans : 0;
    }
};