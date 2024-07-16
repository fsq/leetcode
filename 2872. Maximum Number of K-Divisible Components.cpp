class Solution {
public:
    vector<vector<int>> e;
    int ans = 0, k = 0;

    int dfs(const vector<int>& a, int x, int pre) {
        int tot = a[x];
        for (auto y : e[x])
            if (y != pre) {
                tot += dfs(a, y, x);
                tot %= k;
            }
        if (tot%k == 0) {
            ++ans;
        }
        return tot % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int _k) {
        k = _k;
        e.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }        
        dfs(values, 0, -1);
        return ans;
    }
};