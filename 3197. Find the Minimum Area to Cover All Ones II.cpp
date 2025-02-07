class Solution {
public:
    int n, m;

    int cut1(vector<vector<int>>& a, int x1, int y1, int x2, int y2) {
        int minx = n, maxx = -1, miny = m, maxy = -1;
        for (int i=x1; i<=x2; ++i)
            for (int j=y1; j<=y2; ++j) 
                if (a[i][j] == 1) {
                    minx = min(minx, i);
                    maxx = max(maxx, i);
                    miny = min(miny, j);
                    maxy = max(maxy, j);
                }
        if (maxx==-1) return 10000;
        return (maxx-minx+1) * (maxy-miny+1);
    }

    int cut2(vector<vector<int>>& a, int x1, int y1, int x2, int y2) {
        int ret = 10000;
        for (int i=x1; i+1<=x2; ++i) {
            ret = min(ret, cut1(a, x1, y1, i, y2) + cut1(a, i+1,y1,x2,y2));
        }
        for (int j=y1; j+1<=y2; ++j) {
            ret = min(ret, cut1(a, x1, y1, x2, j) + cut1(a, x1,j+1,x2,y2));
        }
        return ret;
    }

    int minimumSum(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        int ans = n*m;

        for (int i=0; i+1<n; ++i) {
            ans = min(ans, cut1(a, 0, 0, i, m-1) + cut2(a, i+1, 0, n-1, m-1));
            ans = min(ans, cut2(a, 0, 0, i, m-1) + cut1(a, i+1, 0, n-1, m-1));
        }
        for (int j=0; j+1<m; ++j) {
            ans = min(ans, cut1(a, 0, 0, n-1, j) + cut2(a, 0, j+1, n-1, m-1));
            ans = min(ans, cut2(a, 0, 0, n-1, j) + cut1(a, 0, j+1, n-1, m-1));
        }
        return ans;
    }
};