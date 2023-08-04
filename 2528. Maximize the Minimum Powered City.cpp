class Solution {
public:

    bool ok(vector<long long>& a, long long lo, long long k, int r) {
        int n = a.size();
        long long delta = 0;
        unordered_map<int, long long> d;
        for (int i=0; i<n; ++i) {
            if (d.count(i)) delta += d[i];
            long long cur = a[i] + delta;
            if (cur < lo) {
                long long add = lo - cur;
                if (add > k) return false;
                k -= add;
                delta += add;
                d[i+r*2+1] -= add;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& st, int r, int k) {
        vector<long long> a(st.size());
        for (int i=0; i<st.size(); ++i) {
            a[max(i-r, 0)] += st[i];
            if (i+r+1<a.size()) a[i+r+1] -= st[i];
        }
        for (int i=1; i<a.size(); ++i) a[i] += a[i-1];
        long long lf = 0, rt = 2e10;
        while (lf < rt) {
            long long mid = (lf+rt+1) >> 1;
            if (ok(a, mid, k, r)) {
                lf = mid;
            } else {
                rt = mid - 1;
            }
        }
        return lf;
    }
};