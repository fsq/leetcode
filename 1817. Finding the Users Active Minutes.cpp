class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& a, int k) {
        unordered_map<int, unordered_set<int>> um;
        for (const auto& p : a)
            um[p[0]].insert(p[1]);
        
        vector<int> ans(k);
        for (const auto& p : um)
            ++ans[p.second.size() - 1];
        return ans;
    }
};