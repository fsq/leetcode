class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto x : nums)
            if (++m[x] == 2) {
                ans ^= x;
            }
        return ans;
    }
};