using ll = long long;
using vll = vector<ll>;

class Solution {
public:

    ll t[200000][2][2];

    void merge(long long res[2][2], long long a[2][2], long long b[2][2]) {
        res[0][0] = max(max(a[0][0], a[0][1]) + b[0][0], a[0][0] + b[1][0]);
        res[0][1] = max(max(a[0][0], a[0][1]) + b[0][1], a[0][0] + b[1][1]);
        res[1][0] = max(max(a[1][0], a[1][1]) + b[0][0], a[1][0] + b[1][0]);
        res[1][1] = max(max(a[1][0], a[1][1]) + b[0][1], a[1][0] + b[1][1]);
    }

    void update(vector<int>& a, int i, int l, int r, int pos, int val) {
        if (l==r) {
            t[i][1][1] = val;
        } else {
            int m = (l + r) >> 1;
            if (pos <= m) {
                update(a, i*2, l, m, pos, val);
            } else {
                update(a, i*2+1, m+1, r, pos, val);
            }
            merge(t[i], t[i*2], t[i*2+1]);
        }
    }

    void build(vector<int>& a, int i, int l, int r) {
        if (l == r) {
            t[i][0][0] = 0;
            t[i][0][1] = t[i][1][0] = INT_MIN;
            t[i][1][1] = a[l];
        } else {
            int m = (l + r) >> 1;
            build(a, i*2, l, m);
            build(a, i*2+1, m+1, r);
            merge(t[i], t[i*2], t[i*2+1]);
        }
    }

    int maximumSumSubsequence(vector<int>& a, vector<vector<int>>& queries) {
        build(a, 1, 0, a.size()-1);

        ll ans = 0;
        for (auto& q: queries) {
            int p = q[0], x = q[1];
            update(a, 1, 0, a.size()-1, p, x);
            ans += max(max(t[1][0][0], t[1][0][1]), max(t[1][1][0], t[1][1][1]));
            ans %= 1000000007;
        }
        return ans;
    }
};