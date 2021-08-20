class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool peak(vector<vector<int>>& a, int x, int y) {
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && a[tx][ty]>a[x][y])
                    return false;
        }
        return true;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l+r) >> 1;
            int mx=-1, sd=0;
            for (int j=0; j<n; ++j) {
                if (peak(a, j, mid)) {
                    return {j, mid};
                }
                if (mid+1<m && a[j][mid+1]>mx) {
                    mx = a[j][mid+1];
                    sd = 1;
                }
                if (mid-1>=0 && a[j][mid-1]>mx) {
                    mx = a[j][mid-1];
                    sd = 0;
                }
            }
            
            if (sd == 1)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return {0, 0};
    }
};