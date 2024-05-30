class Solution {
public:
    const int M = 1000000007;
    int minimumPossibleSum(int n, int target) {
        long long t = target;
        long long x = t / 2;
        long long ans = 0;
        if (n >= x) {
            ans = (1 + x) * x / 2 % M;
            ans += (t+(t+n-x-1)) % M * (n - x) / 2 % M;
        } else {
            ans = (1ll + n) * n / 2 % M;
        }
        return ans % M;
    }
};