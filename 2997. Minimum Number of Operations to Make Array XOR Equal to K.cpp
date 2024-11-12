class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s = k;
        for (auto x : nums) {
            s ^= x;
        }
        return __builtin_popcount(s);
    }
};