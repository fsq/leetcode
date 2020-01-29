class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for (int i=0; i<m; ++i) {
            vector<int> now;
            for (int j=i,r=0; r<n && j<m; ++r,++j) now.push_back(a[r][j]);
            sort(now.begin(), now.end());
            for (int j=i,r=0; r<n && j<m; ++r,++j) a[r][j] = now[r];
        }
        for (int i=1; i<n; ++i) {
            vector<int> now;
            for (int j=i,r=0; r<m && j<n; ++r,++j) now.push_back(a[j][r]);
            sort(now.begin(), now.end());
            for (int j=i,r=0; r<m && j<n; ++r,++j) a[j][r] = now[r];
        }
        return a;
    }
};