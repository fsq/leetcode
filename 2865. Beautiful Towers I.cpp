class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long cur = a[i];
            for (int j=i-1, x=a[i]; j>=0; --j) {
                x = min(x, a[j]);
                cur += x;
            }
            for (int j=i+1, x=a[i]; j<n; ++j) {
                x = min(x, a[j]);
                cur += x;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};