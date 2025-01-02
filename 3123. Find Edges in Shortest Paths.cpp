class Solution {
public:
    vector<pair<int,int>> e[50001];
    int n;

    vector<int> dijk(int src) {
        vector<int> d(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> q;
        q.push({0, src});
        while (q.size()) {
            auto [w, x] = q.top();
            q.pop();
            if (d[x] != INT_MAX) continue;
            d[x] = w;
            for (auto& pr: e[x]) {
                if (d[pr.first] == INT_MAX) {
                    q.push({w+pr.second, pr.first});
                }
            }
        }
        return d;
    }

    vector<bool> findAnswer(int _n, vector<vector<int>>& edges) {
        n = _n;
        for (auto& pr: edges) {
            e[pr[0]].push_back({pr[1], pr[2]});
            e[pr[1]].push_back({pr[0], pr[2]});
        }
        auto d1 = dijk(0);
        auto d2 = dijk(n-1);
        vector<bool> ans(edges.size(), false);
        int mn = d1[n-1];
        if (mn == INT_MAX) return ans;

        for (int i=0; i<edges.size(); ++i) {
            int x = edges[i][0], y = edges[i][1], w = edges[i][2];
            if ((d1[x]!=INT_MAX && d2[y]!=INT_MAX && d1[x]+d2[y]+w==mn) ||
                (d1[y]!=INT_MAX && d2[x]!=INT_MAX && d1[y]+d2[x]+w==mn)) {
                    ans[i] = true;
                }
        }
        return ans;
    }
};