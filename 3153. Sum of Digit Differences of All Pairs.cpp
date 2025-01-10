class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        for (long long d=1; d<=1000000000; d*=10) {
            unordered_map<int, int> cnt;
            for (auto x : nums) ++cnt[x / d % 10];
            for (auto& pr : cnt) {
                ans += (long long)pr.second * (nums.size()-pr.second);
            }
        }
        return ans / 2;
    }
};