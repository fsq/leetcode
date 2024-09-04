class Solution {
public:
    int minimumSum(vector<int>& a) {
        auto l = a;
        for (int i=1; i<l.size(); ++i) {
            l[i] = min(l[i-1], a[i]);
        }
        int mn = a.back(), ans = INT_MAX;
        for (int j=a.size()-2; j>0; --j) {
            if (l[j-1]<a[j] && a[j]>mn) {
                ans = min(ans, l[j-1]+a[j]+mn);
            }
            mn = min(mn, a[j]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};