class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] == key) {
                if (ans.empty()) {
                    for (int j=max(0, i-k); j<min<int>(nums.size(), i+k+1); ++j)
                        ans.push_back(j);
                } else {
                    if (i+k<=ans.back()) continue;
                    for (int j=max(i-k, ans.back()+1); j<=min<int>(i+k, nums.size()-1); ++j) {
                        ans.push_back(j);                        
                    }
                }
            }
        return ans;
    }
};