class Solution {
public:
    int minCost(vector<int>& a, int k) {
        int n = a.size();
        vector<int> f(n+1, INT_MAX);
        f[0] = 0;
        for (int i=0; i<n; ++i) {
            unordered_map<int, int> m;
            int dist = 0;
            int& ans = f[i+1];
            for (int j=i; j>=0; --j) {
                int cnt = ++m[a[j]];
                if (cnt == 1)
                    ++dist;
                else if (cnt == 2)
                    --dist;
                ans = min(ans, k + (i-j+1-dist) + f[j]);
            }
        }
        return f[n];
    }
};