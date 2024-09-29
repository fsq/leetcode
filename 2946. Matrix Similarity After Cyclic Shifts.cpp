class Solution {
public:
    bool areSimilar(vector<vector<int>>& a, int k) {
        int m = a[0].size();
        for (int i=0; i<a.size(); ++i) {
            for (int j=0; j<m; ++j) {
                int ofst = (i&1) ? -k : k;
                int t = ((j+ofst)%m + m) % m;
                if (a[i][j] != a[i][t]) return false;
            }
        }
        return true;
    }
};