class Solution {
public:
    int minimumLines(vector<vector<int>>& a) {
        if (a.size()<2) return 0;
        sort(a.begin(), a.end());
        int ans = 1;
        long long x1=a[1][0]-a[0][0], y1=a[1][1]-a[0][1], x2, y2;
        for (int i=2; i<a.size(); ++i) {
            x2 = a[i][0] - a[i-1][0];
            y2 = a[i][1] - a[i-1][1];
            if (y1 * x2 != x1 * y2) ++ans;
            x1 = x2, y1 = y2;
        }
        return ans;
    }
};