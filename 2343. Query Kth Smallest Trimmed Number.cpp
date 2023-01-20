class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            vector<pair<string, int>> a;
            for (int i=0; i<nums.size(); ++i) 
                a.push_back({nums[i].substr(nums[i].size()-q[1]), i});
            nth_element(a.begin(), a.begin()+q[0]-1, a.end());
            ans.push_back(a[q[0]-1].second);
        }
        return ans;
    }
};