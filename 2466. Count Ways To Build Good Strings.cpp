class Solution {
public:
    const int M = 1000000007;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high+1);
        f[0] = 1;
        for (int i=0; i<f.size(); ++i) {
            if (i+zero<=high) f[i+zero] = (f[i+zero] + f[i]) % M;
            if (i+one<=high) f[i+one] = (f[i+one] + f[i]) % M;
        }
        int ans = 0;
        for (int i=low; i<=high; ++i)
            ans = (ans + f[i]) % M;
        return ans;
    }
};