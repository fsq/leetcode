class Solution {
public:
    vector<vector<pair<int, int>>> e;
    vector<int> f;
    vector<int> ans;

    int dfs(int x, int fa) {
        int ans = 0;
        for (auto& pr : e[x]) 
            if (pr.first != fa) {
                ans += pr.second + dfs(pr.first, x);
            }
        return ans;
    }

    void calc(int x, int fa) {
        for (auto& pr : e[x])
            if (pr.first == fa) {
                int ofst = pr.second == 0 ? -1 : 1;
                ans[x] = ans[fa] + ofst;
                break;
            }
        for (auto& pr : e[x])
            if (pr.first != fa) {
                calc(pr.first, x);
            }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        e.resize(n);
        f.resize(n);
        ans.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back({pr[1], 0});
            e[pr[1]].push_back({pr[0], 1});
        }
        ans[0] = dfs(0, -1);
        calc(0, -1);
        return ans;
    }
};