class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> s(101);
        for (auto x : nums) ++s[x];
        for (int i=1; i<=100; ++i) s[i] += s[i-1];
        for (auto& x : nums) x = x==0 ? 0 : s[x-1];
        return nums;
    }
};