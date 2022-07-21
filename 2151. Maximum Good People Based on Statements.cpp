class Solution {
public:
    
    inline int good(int m, int x) { return m & (1<<x); }
    inline int bad(int m, int x) { return !good(m, x); }
    
    bool ok(vector<vector<int>>& a, int m) {
        for (auto& st : a) {
            int x=st[0], y=st[1], s=st[2];
            if (s == 0) {
                if (!(good(m, x) && bad(m, y) || bad(m, x))) return false;
            } else {
                if (!(good(m, x) && good(m, y) || bad(m, x))) return false;
            }
        }
        return true;
    }
    
    int maximumGood(vector<vector<int>>& as) {
        int n = as.size();
        vector<vector<int>> a;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (as[i][j]!=2)
                    a.push_back({i, j, as[i][j]});
        vector<int> q;
        for (int i=0; i<(1<<n); ++i) q.push_back(i);
        sort(q.begin(), q.end(), [](int x, int y) { 
            return __builtin_popcount(x) > __builtin_popcount(y);
        });
        for (auto x : q) {
            if (ok(a, x))
                return __builtin_popcount(x);
        }
        return 0;
    }
};