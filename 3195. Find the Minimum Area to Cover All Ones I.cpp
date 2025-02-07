class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int minx = n, maxx = -1, miny = m, maxy = -1;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                if (a[i][j] == 1) {
                    minx = min(minx, i);
                    maxx = max(maxx, i);
                    miny = min(miny, j);
                    maxy = max(maxy, j);
                }
        return (maxx-minx+1) * (maxy-miny+1);
    }
};