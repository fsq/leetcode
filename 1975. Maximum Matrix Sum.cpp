class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long ans = 0, mp = INT_MAX, mn = INT_MIN, sn = 0, cn = 0;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j) 
                if (a[i][j] < 0) {
                    sn += a[i][j];
                    ++cn;
                    mn = max<long long>(mn, a[i][j]);
                } else {
                    ans += a[i][j];
                    mp = min<long long>(mp, a[i][j]);
                }
        if (cn & 1) {
            ans -= sn - mn;
            if (mp!=INT_MAX && -mn > mp) {
                ans = ans - mp - mp - mn;
            } else 
                ans += mn;
        } else {
            ans -= sn;
        }
        return ans;
    }
};