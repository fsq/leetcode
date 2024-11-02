class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& a) {
        int n = a.size();
        vector<int> l(n), r(n);
        l[0] = r[n-1] = true;
        for (int i=1; i<n; ++i)
            if (a[i] > a[i-1]) {
                l[i] = true;
            } else {
                break;
            }
        for (int i=n-2; i>=0; --i)
            if (a[i] < a[i+1]) {
                r[i] = true;
            } else {
                break;
            }
        long long ans = 0;
        for (int i=0,j=0; i<n; ++i) {
            int pre = i==0 ? INT_MIN: a[i-1];
            j = max(i, j);
            while (j+1<n && !(r[j+1] && a[j+1]>pre)) ++j;
            ans += n-j;
            if (!l[i]) break;
        }
        return ans;
    }
};