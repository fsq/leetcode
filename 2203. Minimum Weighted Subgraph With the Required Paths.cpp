class Solution {
public:
    const long long INF = 10000000001;
    using lipair = pair<long long, int>;
    vector<long long> dijk(vector<vector<pair<int,int>>>& e, int x) {
        vector<long long> d(e.size(), INF);
        vector<bool> vis(e.size());
        priority_queue<lipair, std::vector<lipair>,  std::greater<lipair>> q;
        q.push({0, x});
        d[x] = 0;
        for (int i=0; i<e.size(); ++i) {
            int y = 0;
            long long dis = -1;
            while (q.size())
                if (vis[q.top().second]) {
                    q.pop();
                } else {
                    y = q.top().second;
                    dis = q.top().first;
                    q.pop();
                    break;
                }
            if (dis == -1) break;
            vis[y] = true;
            for (auto& eg : e[y])
                if (!vis[eg.first] && d[y]+eg.second<d[eg.first]) {
                    d[eg.first] = d[y] + eg.second;
                    q.push({d[y]+eg.second, eg.first});
                }
        }
        return d;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> e(n, vector<pair<int,int>>()), re = e;
        for (auto& pr : edges) {
            e[pr[0]].push_back({pr[1], pr[2]});
            re[pr[1]].push_back({pr[0], pr[2]});
        }
        
        auto d1 = dijk(e, src1), d2 = dijk(e, src2), de = dijk(re, dest);
        long long ans = INF;
        for (int i=0; i<n; ++i)
            if (de[i]!=INF && d1[i]!=INF && d2[i]!=INF)
                ans = min(ans, de[i]+d1[i]+d2[i]);
        return ans==INF ? -1 : ans;
    }
};