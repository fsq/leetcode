class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& a) {
        vector<int> ans(a[0].size());
        for (auto& r : a)
            for (int j=0; j<r.size(); ++j) {
                ans[j] = max<int>(ans[j], to_string(r[j]).size());
            }
        return ans;
    }
};