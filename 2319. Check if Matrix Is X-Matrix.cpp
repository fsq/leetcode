class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& a) {
        int n = a.size();
        auto is_dig = [&](int x, int y) {
            return x==y || x+y==n-1;
        };
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (is_dig(i, j) && a[i][j]==0 ||
                   !is_dig(i, j) && a[i][j]!=0)
                   return false;
        return true;
    }
};