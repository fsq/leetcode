class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> a(32);
        for (auto x : nums)
            for (int i=0; i<32; ++i)
                a[i] += x>>i & 1;
        int ans = 0;
        for (auto x : a)
            ans += x * (nums.size()-x);
        return ans;
    }
};