class Solution {
public:

    int spd;

    int dfs(vector<vector<pair<int,int>>>& e, int x, int dis, int pre) {
        int ans = 0;
        if (dis % spd == 0) ++ans;
        for (auto& pr: e[x])
            if (pr.first != pre)
                ans += dfs(e, pr.first, dis+pr.second, x);
        return ans;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        spd = signalSpeed;
        vector<vector<pair<int,int>>> e(n);
        for (auto& g : edges) {
            e[g[0]].push_back({g[1], g[2]});
            e[g[1]].push_back({g[0], g[2]});
        }
        vector<int> ans;
        for (int server=0; server<n; ++server) {
            vector<int> a;
            int tot = 0;
            for (auto pr: e[server]) {
                int cnt = dfs(e, pr.first, pr.second, server);
                a.push_back(cnt);
                tot += cnt;
            }
            int sum = 0;
            for (auto x : a)
                sum += x * (tot-x);
            ans.push_back(sum / 2);
        }
        return ans;
    }
};