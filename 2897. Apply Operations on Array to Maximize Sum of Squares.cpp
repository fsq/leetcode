class Solution {
public:
    int maxSum(vector<int>& a, int k) {
        vector<int> c(32);
        for (auto x : a) {
            for (int i=31; i>=0; --i)
                if (x & (1<<i)) {
                    ++c[i];
                }
        }
        long long ans = 0;
        while (k--) {
            long long x = 0;
            for (int i=0; i<32; ++i)
                if (c[i] > 0) {
                    x |= 1 << i;
                    --c[i];
                }
            ans = (ans + x * x) % 1000000007;
        }
        return ans;
    }
};