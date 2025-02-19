class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int cost_r = 0, cost_c = 0;
        for (auto& r: a) {
            for (int i=0, j=r.size()-1; i<j; ++i, --j)
                cost_r += r[i] ^ r[j];
        }
        for (int m=0; m<a[0].size(); ++m) {
            for (int i=0, j=a.size()-1; i<j; ++i, --j)
                cost_c += a[i][m] ^ a[j][m];
        }
        return min(cost_r, cost_c);
    }
};