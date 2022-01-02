class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rs) {
        unordered_map<int, vector<int>> e;
        for (int i=0; i<rs.size(); ++i) e[rs[i][1]].push_back(i);
        vector<long long> f(n+1);
        for (int i=1; i<=n; ++i) {
            f[i] = f[i-1];
            for (auto x : e[i])
                f[i] = max(f[i], f[rs[x][0]]+rs[x][2]+i-rs[x][0]);
        }
        return f.back();
    }
};