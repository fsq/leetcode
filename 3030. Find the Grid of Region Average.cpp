class Solution {
public:

    bool IsRegion(vector<vector<int>>& a, int x, int y, int threshold) {
        for (int i=x-1; i<=x+1; ++i)
            for (int j=y-1; j<=y; ++j)
                if (abs(a[i][j+1] - a[i][j]) > threshold)
                    return false;
        for (int j=y-1; j<=y+1; ++j)
            for (int i=x-1; i<=x; ++i)
                if (abs(a[i+1][j] - a[i][j]) > threshold)
                    return false;
        return true;
    }

    vector<vector<int>> resultGrid(vector<vector<int>>& a, int threshold) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> s(n, vector<int>(m)), cnt(n, vector<int>(m));
        for (int i=1; i+1<n; ++i)
            for (int j=1; j+1<m; ++j)
                if (IsRegion(a, i, j, threshold)) {
                    int sum = 0;
                    for (int x=i-1; x<=i+1; ++x)
                        for (int y=j-1; y<=j+1; ++y) {
                            sum += a[x][y];
                        }
                    sum /= 9;
                    for (int x=i-1; x<=i+1; ++x)
                        for (int y=j-1; y<=j+1; ++y) {
                            s[x][y] += sum;
                            ++cnt[x][y];
                        }
                }
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (cnt[i][j] == 0) {
                    s[i][j] = a[i][j];
                } else {
                    s[i][j] /= cnt[i][j];
                }
        return s;
    }
};