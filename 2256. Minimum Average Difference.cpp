class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        long long s = accumulate(a.begin(), a.end(), 0ll), pre = 0, diff = s;
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            pre += a[i];
            s -= a[i];
            long long x = pre / (i+1), y = (i+1==a.size() ? 0 : s / (a.size()-i-1));
            if (abs(x - y) < diff) {
                diff = abs(x - y);
                ans = i;
            }
        }
        return ans;
    }
};