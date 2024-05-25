class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& o) {
        vector<int> f(n+1);
        unordered_map<int, vector<int>> m;
        for (int i=0; i<o.size(); ++i) {
            m[o[i][1]].push_back(i);
        }
        for (int i=1; i<=n; ++i) {
            f[i] = f[i-1];
            for (auto k : m[i-1]) {
                f[i] = max(f[i], f[o[k][0]] + o[k][2]);
            }
        }
        return f.back();
    }
};