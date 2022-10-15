class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> c(1001);
        for (auto& a : nums)
            for (auto x : a)
                ++c[x];
        vector<int> ans;
        for (int i=1; i<=1000; ++i)
            if (c[i] == nums.size())
                ans.push_back(i);
        return ans;
    }
};