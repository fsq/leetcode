using MAT = vector<vector<long long>>;

class Solution {
public:

    const int M = 1000000007;

    vector<int> calc_next(string& s) {
        vector<int> next(s.size());
        int i = 1;
        int len = 0;
        while (i < s.size())
            if (s[i] == s[len]) {
                next[i++] = ++len;
            } else {
                if (len > 0) {
                    len = next[len - 1];
                } else {
                    ++i;
                }
            }
        return next;
    }

    vector<int> calc_match(string& s, string& t, vector<int>& next) {
        int i = 0; // index of pattern
        int j = 0;
        vector<int> match;
        while (j < t.size())
            if (s[i] == t[j]) {
                ++i, ++j;
                if (i == s.size()) {
                    if (j-i<t.size()/2) match.push_back(j - i);
                    i = next[i - 1];
                }
            } else {
                if (i > 0) {
                    i = next[i - 1];
                } else {
                    ++j;
                }
            }
        return match;
    }

    MAT mult(const MAT& a, const MAT& b) {
        MAT c(2, vector<long long>(2));
        for (int i=0; i<2; ++i)
            for (int j=0; j<2; ++j)
                for (int k=0; k<2; ++k)
                    c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % M;
        return c;
    }

    MAT pow(const MAT& base, int l, long long k) {
        if (k == 0) {
            return {{1, 0}, {0, 1}};
        }
        if (k == 1) {
            return base;
        }
        auto s = pow(base, l, k / 2);

        auto ret = mult(s, s);
        if (k & 1) {
            ret = mult(ret, base);
        }
        return ret;
    }

    vector<long long> get_power(int l, long long k) {
        const MAT base = {{0, l-1}, {1, l-2}};
        auto mat = pow(base, l, k);
        int f0 = 1, g0 = 0;
        return {(mat[0][0]*f0+mat[0][1]*g0) % M, (mat[1][0]*f0+mat[1][1]*g0) % M};
    }

    int numberOfWays(string s, string t, long long k) {
        auto next = calc_next(s);
        t += t;
        auto p = calc_match(s, t, next);
        // for (auto x : p) cout << x << ' '; cout << endl;
        int ans = 0;
        vector<long long> fg = get_power(s.size(), k);
        // cout << fg[0] << ' ' << fg[1] << endl;
        for (auto x : p)
            ans = (ans + fg[x != 0]) % M;
        return ans;
    }
};