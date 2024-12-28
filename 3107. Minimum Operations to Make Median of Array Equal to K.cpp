class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i=a.size()/2; i<a.size() && a[i]<k; ++i) {
            ans += k - a[i];
            a[i] = k;
        }
        for (int i=(int)a.size()/2-1; i>=0 && a[i]>k; --i) {
            ans += a[i] - k;
        }
        if (a[a.size()/2] != k) ans += a[a.size()/2] - k;
        return ans;
    }
};