class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> m;
        for (auto& seg : segments) {
            m[seg[0]] += seg[2];
            m[seg[1]] -= seg[2];
        }
        vector<vector<long long>> ans;
        long long cur = 0, l = -1;
        for (auto & pr : m) {
            if (cur != 0) {
                ans.push_back({l, pr.first, cur});
            }
            cur += pr.second;
            l = pr.first;
        }
        return ans;
    }
};