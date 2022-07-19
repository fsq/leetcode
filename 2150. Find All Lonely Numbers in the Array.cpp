class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums) ++m[x];
        
        vector<int> ans;
        for (auto& pr : m) {
            if (pr.second > 1) continue;
            int x = pr.first;
            if (!m.count(x-1) && !m.count(x+1)) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};