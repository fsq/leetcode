class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& a) {
        for (int j=0; j<a[0].size(); ++j) {
            int mx = -1;
            for (int i=0; i<a.size(); ++i) mx = max(mx, a[i][j]);
            for (int i=0; i<a.size(); ++i)
                if (a[i][j] == -1)
                    a[i][j] = mx;
        }
        return a;
    }
};