class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> d(n);
        for (auto& r : roads) {
            ++d[r[0]];
            ++d[r[1]];
        }
        sort(d.begin(), d.end());
        long long ans = 0;
        for (long long i=1; i<=n; ++i)
            ans += i * d[i-1];
        return ans;
    }
};