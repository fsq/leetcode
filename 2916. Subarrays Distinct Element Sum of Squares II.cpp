class Solution {
public:
    const int M = 1000000007;
    int t[400000], s[400000];

    void add(int x, int lf, int rt, int l, int r) {
        if (l<=lf && rt<=r) {
            t[x] = (t[x] + 1) % M;
            s[x] = (s[x] + (rt-lf+1)) % M;
        } else {
            int mid = (lf + rt) >> 1;
            if (t[x] > 0) {
                t[x*2] = (t[x*2] + t[x]) % M;
                s[x*2] = (s[x*2] + (long long)t[x]*(mid-lf+1)) % M;
                t[x*2+1] = (t[x*2+1] + t[x]) % M;
                s[x*2+1] = (s[x*2+1] + (long long)t[x]*(rt-mid)) % M;
                t[x] = 0;
            }
            if (l<=mid) add(x*2, lf, mid, l, r);
            if (r>mid) add(x*2+1, mid+1, rt, l, r);
            s[x] = (s[x*2] + s[x*2+1]) % M;
        }
    }

    int query(int x, int lf, int rt, int l, int r) {
        if (l<=lf && rt<=r) {
            return s[x];
        } else {
            int mid = (lf + rt) >> 1;
            if (t[x] > 0) {
                t[x*2] = (t[x*2] + t[x]) % M;
                s[x*2] = (s[x*2] + (long long)t[x]*(mid-lf+1)) % M;
                t[x*2+1] = (t[x*2+1] + t[x]) % M;
                s[x*2+1] = (s[x*2+1] + (long long)t[x]*(rt-mid)) % M;
                t[x] = 0;
            }
            int ret = 0;
            if (l<=mid) ret = (ret + query(x*2, lf, mid, l, r)) % M;
            if (r>mid) ret = (ret + query(x*2+1, mid+1, rt, l, r)) % M;
            return ret;            
        }
    }

    int sumCounts(vector<int>& a) {
        int n = a.size();
        memset(t, 0, sizeof(t));
        memset(s, 0, sizeof(s));
        vector<long long> f(n+1); // sigma of x^2, starting from i
        unordered_map<int, int> nxt;
        for (int i=n-1; i>=0; --i) {
            int j = nxt.count(a[i]) ? nxt[a[i]] : n;
            f[i] = f[i+1] + (j-i);
            if (i+1 <= j-1) {
                int p = query(1,0,n-1, i+1, j-1);
                f[i] = (f[i] + 2 * (long long)p) % M;
            }
            if (i <= j-1) {
                add(1, 0, n-1, i, j-1);
            }
            nxt[a[i]] = i;
        }
        int ans = 0;
        for (int i=0; i<n; ++i) ans = (ans + f[i]) % M;
        return ans;
    }
};