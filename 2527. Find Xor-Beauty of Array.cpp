class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        vector<long long> b(32);
        for (auto x : nums) {
            for (int i=0; x; ++i, x>>=1)
                b[i] += x & 1;
        }
        int ans = 0;
        long long n = nums.size();
        for (int i=0; i<b.size(); ++i) {
            long long x = b[i], y = (n*n - (n-x)*(n-x)) * x;
            ans |= (y & 1) << i;
        }
        return ans;
    }
};