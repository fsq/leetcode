class Solution {
public:
    const int M = 1e9 + 7;
    int numberWays(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> f(41, vector<int>(1<<n, 0));
        vector<vector<int>> h(41, vector<int>());
        unordered_set<int> st;
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (auto x : a[i]) {
                h[x].push_back(i);
                st.insert(x);
            }
        f[0][0] = 1;
        for (int hat=1; hat<=40; ++hat) 
            if (st.count(hat)) {
                f[hat][0] = 1;
                for (int msk=1; msk<(1<<n); ++msk)
                    if (__builtin_popcount(msk)<=hat) {
                        f[hat][msk] = (f[hat][msk] + f[hat-1][msk]) % M;
                        for (auto j : h[hat]) 
                            if ((msk>>j) & 1) {
                                f[hat][msk] = (f[hat][msk] + f[hat-1][msk ^ (1<<j)]) % M;
                            }
                    }
            } else {
                f[hat] = f[hat-1];
            }
        return f[40][(1<<n)-1];
    }
};