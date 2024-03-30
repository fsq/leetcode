class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& log, int x, vector<int>& queries) {
        map<int, vector<int>> req;
        unordered_map<int, int> m;
        sort(log.begin(), log.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int,int>> qs;
        vector<int> ans(queries.size());
        for (int i=0; i<queries.size(); ++i) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());
        int i = 0;
        for (auto& [time, qi] : qs) {
            while (i<log.size() && log[i][1]<=time) {
                req[log[i][1]].push_back(log[i][0]);
                ++m[log[i][0]];
                ++i;
            }
            while (req.size() && req.begin()->first<time-x) {
                for (auto x : req.begin()->second) {
                    if (--m[x]==0) m.erase(x);
                }
                req.erase(req.begin());
            }
            ans[qi] = n - m.size();
        }
        return ans;
    }
};