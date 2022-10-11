class Solution {
public:
    int maximumScore(vector<int>& a, vector<vector<int>>& edges) {
        int n = a.size();
        vector<set<pair<int,int>, std::greater<pair<int,int>>>> st(n);
        for (int i=0; i<edges.size(); ++i) {
            auto &e = edges[i];
            auto &s0 = st[e[0]];
            auto &s1 = st[e[1]];
            s0.insert({a[e[1]], e[1]});
            if (s0.size() > 3) s0.erase(prev(s0.end()));
            s1.insert({a[e[0]], e[0]});
            if (s1.size() > 3) s1.erase(prev(s1.end()));
        }
        
        int ans = -1;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            for (auto& p1 : st[x])
                for (auto& p2 : st[y]) {
                    if (p1.second != y && p2.second != x && p1.second!=p2.second) {
                        ans = max(ans, a[x]+a[y]+a[p1.second]+a[p2.second]);
                    }
                }
        }
        return ans;
    }
};