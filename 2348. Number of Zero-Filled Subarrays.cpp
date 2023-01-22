class Solution {
public:

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, l = 0;
        for (auto x : nums) 
            if (x == 0) {
                ++l;
                ans += l;
            } else {
                l = 0;
            }
        return ans;
    }
};