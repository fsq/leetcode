class Solution {
public:
    int minDifference(vector<int>& a) {
        if (a.size()<=3) return 0;
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = a[n-4] - a[0];
        ans = min(ans, a[n-3] - a[1]);
        ans = min(ans, a[n-2] - a[2]);
        ans = min(ans, a[n-1] - a[3]);
        return ans;
    }
};