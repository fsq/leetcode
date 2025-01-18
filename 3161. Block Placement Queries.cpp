class Solution {
public:

    int t[200000];

    void update(int i, int l, int r, int x, int v) {
        if (l==r) {
            t[i] = v;
        } else {
            int m = (l + r) >> 1;
            if (x <= m) {
                update(i*2, l, m, x, v);
            } else {
                update(i*2+1, m+1, r, x, v);
            }
            t[i] = max(t[i*2], t[i*2+1]);
        }
    }

    int find(int i, int l, int r, int le, int rt) {
        if (le<=l && r<=rt) {
            return t[i];
        } else {
            int m = (l+r) >> 1;
            int ans = -1;
            if (le <= m) {
                ans = find(i*2, l, m, le, rt);
            }
            if (rt > m) {
                ans = max(ans, find(i*2+1, m+1, r, le, rt));
            }
            return ans;
        }
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = 0;
        for (auto& q : queries) n = max(n, q[1]);
        memset(t, -1, sizeof(t));
        set<int> st = {0};
        for (auto& q : queries) {
            int x = q[1];
            if (q[0] == 1) {
                auto [it, done] = st.insert(x);
                update(1, 1, n, x, x-*prev(it));
                if (next(it) != st.end()) {
                    update(1, 1, n, *next(it), *next(it)-x);
                }
            } else {
                int sz = q[2];
                auto mx = find(1, 1, n, 1, x);
                auto it = st.upper_bound(x);
                if (it != st.begin()) {
                    mx = max(mx, x - *prev(it));
                }
                ans.push_back(mx >= sz);
            }
        }
        return ans;
    }
};