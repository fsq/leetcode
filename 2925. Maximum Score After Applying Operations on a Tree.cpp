class Solution {
public:

    long long dfs(int x, int pre, vector<vector<int>>& e, vector<int>& v) {
        long long ret = 0;
        for (auto y : e[x])
            if (y != pre) {
                ret += dfs(y, x, e, v);
            }
        return ret == 0 ? v[x] : min<long long>(ret, v[x]);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> e(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        long long ans = 0;
        for (auto x : v) ans += x;
        return ans - dfs(0, -1, e, v);
    }
};