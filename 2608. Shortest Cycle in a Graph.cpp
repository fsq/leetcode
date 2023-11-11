class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        for (auto &pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        int ans = INT_MAX;
        for (auto& pr : edges) {
            int u=pr[0], v=pr[1];
            queue<int> q;
            q.push(u);
            vector<int> d(n);
            d[u] = 1;
            while (q.size()) {
                for (int _t=q.size(); _t; --_t) {
                    int x = q.front(); q.pop();
                    for (auto y : e[x])
                        if (!d[y] && !(u==x&&v==y || u==y&&v==x)) {
                            d[y] = d[x]+1;
                            if (y==v) goto summary;
                            q.push(y);
                        }
                }
            }
            summary:
            if (d[v]) ans = min(ans, d[v]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};