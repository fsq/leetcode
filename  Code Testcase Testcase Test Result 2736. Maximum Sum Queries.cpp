class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        // sort by nums1 asc
        sort(a.begin(), a.end(), [&](int x, int y) {
            return nums1[x] < nums1[y];
        });
        vector<vector<int>> q;
        for (int i=0; i<queries.size(); ++i) {
            q.push_back({queries[i][0], i});
        }
        // sort by xi desc
        sort(q.rbegin(), q.rend());

        vector<int> ans(q.size());
        map<int, int> m;
        for (auto& qr : q) {
            int qi = qr[1], xi = queries[qi][0], yi = queries[qi][1];
            while (a.size() && nums1[a.back()]>=xi) {
                int y = nums2[a.back()], sum = nums1[a.back()]+nums2[a.back()];
                auto it = m.find(y);
                if (it != m.end()) {
                    it->second = max(it->second, sum);
                } else {
                    it = m.insert({y, sum}).first;
                }
                if (next(it)!=m.end() && next(it)->second>=it->second) {
                    m.erase(it);
                } else {
                    while (it!=m.begin() && it->second >= prev(it)->second) {
                        m.erase(prev(it));
                    }
                }
                a.pop_back();
            }
            auto it = m.lower_bound(yi);
            ans[qi] = it==m.end() ? -1 : it->second;
        }
        return ans;
    }
};