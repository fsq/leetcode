class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> cnt;
        for (auto x : nums) {
            auto c = ++cnt[x];
            if (c>ans.size()) ans.push_back(vector<int>());
            ans[c-1].push_back(x);
        }
        return ans;
    }
};