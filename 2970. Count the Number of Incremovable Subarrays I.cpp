class Solution {
public:
    int incremovableSubarrayCount(vector<int>& a) {
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
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=i; j<n; ++j) {
                if ((i==0 || l[i-1]) && (j==n-1 || r[j+1])) {
                    int x = i==0 ? INT_MIN : a[i-1];
                    int y = j+1==n ? INT_MAX : a[j+1];
                    if (x < y) {
                        ++ans;
                    }
                }
            }
        return ans;
    }
};