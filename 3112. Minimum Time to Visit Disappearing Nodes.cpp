class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> e(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back({pr[1], pr[2]});
            e[pr[1]].push_back({pr[0], pr[2]});
        }
        vector<int> d(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> q;
        q.push({0, 0});
        while (q.size()) {
            auto [dis, x] = q.top();
            q.pop();
            if (d[x] != INT_MAX) continue;
            if (disappear[x]<=dis) {
                d[x] = -1;
                continue;
            }
            d[x] = dis;
            for (auto& pr : e[x]) {
                q.push({d[x]+pr.second, pr.first});
            }
        }
        for (auto& x : d)
            if (x == INT_MAX)
                x = -1;
        return d;
    }
};