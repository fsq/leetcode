class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& a) {
        if (a[0][0] != 0) return false;
        int n = a.size();
        vector<vector<int>> p(n*n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                int ind = a[i][j];
                if (!p[ind].empty()) return false;
                p[ind] = {i, j};
            }
        for (int i=0; i+1<p.size(); ++i) {
            int dx = abs(p[i+1][0]-p[i][0]), dy = abs(p[i+1][1]-p[i][1]);
            if (!(dx!=0 && dy!=0 && dx+dy==3)) return false;
        }
        return true;
    }
};