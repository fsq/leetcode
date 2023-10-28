class Solution {
public:

    long long f(vector<int>& a, long long t) {
        long long ans = 0;
        for (long long x : a) {
            // x*n^2<=t ==> n <= sqrt(t/x)
            ans += (long long)sqrt((double)t / x);
        }
        return ans;
    }

    long long repairCars(vector<int>& a, long long cars) {
        long long l = 1, r = a[0] * cars * cars;
        while (l < r) {
            long long mid = (l+r) >> 1;
            long long fix = f(a, mid);
            if (fix < cars) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};