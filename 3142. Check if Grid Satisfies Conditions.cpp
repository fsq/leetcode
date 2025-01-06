class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& a) {
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j) {
                if (i+1<a.size() && a[i][j]!=a[i+1][j]) return false;
                if (j+1<a[0].size() && a[i][j]==a[i][j+1]) return false;
            }
        return true;
    }
};