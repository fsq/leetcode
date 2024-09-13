class Solution {
public:

    long long t[400000];

    long long query(int x, int l, int r, int le, int rt) {
        if (le<=l && r<=rt) {
            return t[x];
        }
        int m = (l+r) >> 1;
        if (rt <= m) {
            return query(x*2, l, m, le, rt);
        } else if (le > m) {
            return query(x*2+1, m+1, r, le, rt);
        } else {
            return max(query(x*2, l, m, le, rt), query(x*2+1, m+1, r, le, rt));
        }
    }

    void update(int x, int l, int r, int ind, long long val) {
        if (l==ind && r==ind) {
            t[x] = val;
        } else {
            int m = (l+r) >> 1;
            if (ind <= m) {
                update(x*2, l, m, ind, val);
            } else {
                update(x*2+1, m+1, r, ind, val);
            }
            t[x] = max(t[x*2], t[x*2+1]);
        }
    }

    long long maxBalancedSubsequenceSum(vector<int>& a) {
        vector<int> b;
        for (int i=0; i<a.size(); ++i) b.push_back(a[i] - i);
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        unordered_map<int, int> v2i;
        for (int i=0; i<b.size(); ++i) v2i[b[i]] = i + 1;

        int n = b.size();
        long long f = INT_MIN;
        for (int i=0; i<a.size(); ++i) {
            long long q = max(0ll, query(1, 1, n, 1, v2i[a[i] - i]));
            f = max(f, q + a[i]);
            update(1, 1, n, v2i[a[i] - i], q + a[i]);
        }
        return f;
    }
};