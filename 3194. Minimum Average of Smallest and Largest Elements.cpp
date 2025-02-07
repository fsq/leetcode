class Solution {
public:
    double minimumAverage(vector<int>& a) {
        sort(a.begin(), a.end());
        double ans = 10000;
        for (int i=0, j=a.size()-1; i<j; ++i, --j) {
            ans = min(ans, (a[i]+a[j])/2.0);
        }
        return ans;
    }
};