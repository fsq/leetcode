class Solution {
public:
    
    bool ok(int pre, int now) {
        return (pre & (now<<1))==0 && (pre & (now>>1))==0;
    }
    
    int maxStudents(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> f(n, vector<int>(1<<m));
        for (int i=0; i<n; ++i) {
            int row = 0;
            for (int j=0; j<m; ++j)
                if (a[i][j]=='#')
                    row |= 1 << j;
            for (int s=0; s<(1<<m); ++s) // current row
                if ((s & row) == 0 && (s & (s<<1))==0 && (s & (s>>1))==0) {// can set to s
                    int cnt = __builtin_popcount(s);
                    if (i == 0) 
                        f[i][s] = cnt;
                    else {
                        for (int t=0; t<(1<<m); ++t) // prev row
                            if (f[i-1][t]!=-1 && ok(t, s))
                                f[i][s] = max(f[i][s], f[i-1][t] + cnt);
                    }
                } else 
                    f[i][s] = -1;
        }
        return *max_element(f.back().begin(), f.back().end());
    }
};