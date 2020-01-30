class Solution {
public:
    int maxValueAfterReverse(vector<int>& a) {
        int lo = INT_MAX, hi = INT_MIN, tot = 0;
        for (int i=0; i+1<a.size(); ++i) {
            int x = a[i], y = a[i+1];
            lo = min(lo, max(x, y));
            hi = max(hi, min(x, y));
            tot += abs(y - x);
        }
        int ans = max(tot, tot + 2 * (hi - lo));
        for (int i=0; i<a.size(); ++i) {
            if (i+1<a.size()) ans = max(ans, tot + abs(a[i+1]-a[0]) - abs(a[i+1]-a[i]));
            if (i-1>=0) ans = max(ans, tot + abs(a.back()-a[i-1]) - abs(a[i]-a[i-1]));
        }
        return ans;
    }
};