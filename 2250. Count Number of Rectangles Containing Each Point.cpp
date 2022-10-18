class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rs, vector<vector<int>>& ps) {
        sort(rs.begin(), rs.end());
        for (int i=0; i<ps.size(); ++i) ps[i].push_back(i);
        sort(ps.begin(), ps.end());
        vector<int> h(101);
        for (auto& r : rs) ++h[r[1]];
        vector<int> ans(ps.size());
        int i = 0;
        for (auto& p : ps) {
            while (i<rs.size() && rs[i][0] < p[0]) {
                --h[rs[i][1]];
                ++i;
            }
            ans[p[2]] = accumulate(h.begin()+p[1], h.end(), 0);
        }
        return ans;
    }
};