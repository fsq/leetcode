class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums) ++m[x];
        vector<int> ans(2);
        for (auto& pr : m) {
            ans[0] += pr.second / 2;
            ans[1] += pr.second % 2;
        }
        return ans;
    }
};