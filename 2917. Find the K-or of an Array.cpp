class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> a(32);
        int ans = 0;
        for (auto x : nums)
            for (int i=0; i<32; ++i) {
                a[i] += (x >> i) & 1;
                if (a[i] >= k) ans |= 1 << i;
            }
        return ans;
    }
};