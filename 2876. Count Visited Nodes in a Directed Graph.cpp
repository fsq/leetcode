class Solution {
public:
    vector<int> ans, dp;

    // -1: met other CC
    // x: met ancestor x
    int dfs(vector<int>& e, int x, int d) {
        dp[x] = d;
        int y = e[x];
        // visited CC
        if (ans[y] != 0) {
            ans[x] = ans[y] + 1;
            return -1;
        }
        // ancestor
        if (dp[y] > 0) {
            ans[x] = dp[x] - dp[y] + 1;
            return y;
        }
        auto r = dfs(e, y, d+1);
        if (r == -1) {
            ans[x] = ans[y] + 1;
            return r;
        } else {
            ans[x] = ans[y];
            return x==r ? -1 : r;
        }
    }

    vector<int> countVisitedNodes(vector<int>& e) {
        int n = e.size();
        ans.resize(n);
        dp.resize(n);
        for (int i=0; i<n; ++i)
            if (ans[i] == 0) {
                dfs(e, i, 1);
            }
        return ans;
    }
};