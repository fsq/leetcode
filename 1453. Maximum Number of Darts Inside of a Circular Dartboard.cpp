class Solution {
public:
    
    long double dist(double x1, double y1, double x2, double y2) {
        return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    }
    
    int numPoints(vector<vector<int>>& a, int r) {
        int ans = 1, n = a.size();
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j) {
                long double x1=a[i][0], y1=a[i][1], x2=a[j][0], y2=a[j][1];
                long double d = dist(x1, y1, x2, y2) / 4.0;
                if (d > r*r) continue;
                auto x0 = (x1 + x2) / 2.0 + (y2 - y1) * sqrt(r * r - d) / sqrt(d * 4);
                auto y0 = (y1 + y2) / 2.0 - (x2 - x1) * sqrt(r * r - d) / sqrt(d * 4);
                int res = count_if(a.begin(), a.end(), [=](vector<int>& p) {
                    return dist(p[0], p[1], x0, y0) <= r*r+0.0001;
                });
                ans = max(ans, res);
            }
        return ans;
    }
};