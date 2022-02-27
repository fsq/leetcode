class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> m;
        for (auto x : nums1) m[x] |= 1;
        for (auto x : nums2) m[x] |= 2;
        for (auto x : nums3) m[x] |= 4;
        vector<int> ans;
        for (auto& pr : m)
            if (pr.second>=3 && pr.second!=4)
                ans.push_back(pr.first);
        return ans;
    }
};