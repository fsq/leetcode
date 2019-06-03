class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& a) {
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto& r : a) {
            string s;
            for (auto c : r)
                s.push_back(c ^ r[0]);
            ans = max(ans, ++mp[s]);
        }
        return ans;
    }
};