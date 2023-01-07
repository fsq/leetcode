class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> a;
        long long tx = 0;
        for (int i=0; i<nums1.size();  ++i) {
            a.push_back(abs(nums1[i] - nums2[i]));
            tx += a.back();
        }
        k1 += k2;
        if (k1 >= tx) return 0;

        sort(a.rbegin(), a.rend());
        long long s = 0, i;
        for (i=0; i<a.size(); ++i) {
            if (s - i*a[i] >= k1) break;
            s += a[i];
        }
        if (i > 0) {
            k1 -= s - i * a[i-1];
            long long sub = k1 / i, rm = k1 % i;
            for (int j=0; j<i; ++j) {
                a[j] = a[i-1] - sub;
                if (j < rm) --a[j];
            }
        }
        long long ans = 0;
        for (auto x : a) ans += x * x;
        return ans;
    }
};