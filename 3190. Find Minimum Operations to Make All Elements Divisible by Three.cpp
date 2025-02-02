class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            int r = x % 3;
            ans += min(r, 1);
        }
        return ans;
    }
};