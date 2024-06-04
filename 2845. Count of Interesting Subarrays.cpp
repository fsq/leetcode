class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mo, int k) {
        int cur = 0;
        long long ans = 0;
        unordered_map<int, int> r;
        r[0] = 1;
        for (auto num : nums) {
            int x = (num % mo) == k;
            cur += x;
            ans += r[(cur%mo - k + mo) % mo];
            ++r[cur % mo];
        }
        return ans;
    }
};