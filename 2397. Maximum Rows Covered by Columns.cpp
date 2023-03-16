class Solution {
public:
    int maximumRows(vector<vector<int>>& a, int numSelect) {
        int n = a.size(), m = a[0].size();
        vector<int> bs(n);
        for (int i=0; i<n; ++i) {
            int msk = 0;
            for (int j=0; j<m; ++j)
                if (a[i][j] == 1)
                    msk |= 1 << j;
            bs[i] = msk;
        }
        int ans = 0;
        for (int s=1; s<(1<<m); ++s)
            if (__builtin_popcount(s) == numSelect) {
                int cnt = 0;
                for (auto b : bs)
                    if ((b&s)==b || (b==0))
                        ++cnt;
                ans = max(ans, cnt);
            }
        return ans;
    }
};