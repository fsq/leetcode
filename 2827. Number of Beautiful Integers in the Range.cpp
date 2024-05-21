class Solution {
public:
    // f[i][bound][even-odd+10][leading zero?][rem]
    int f[11][2][21][2][20];
    int k;

    int dp(string num, int i, bool bound, int df, bool leading_zero, int rem) {
        if (i == num.size()) {
            return df == 10 && rem == 0;
        }
        int& ans = f[i][bound][df][leading_zero][rem];
        if (ans != -1)
            return ans;
        
        ans = 0;
        int start = 0;
        if (leading_zero) {
            ans += dp(num, i+1, false, df, true, rem);
            start = 1;
        }
        
        int end = bound ? (num[i]-'0') : 9;
        for (int x=start; x<=end; ++x) {
            // (x*10^t%k + r) % k == rem
            int r = (rem - x * (int)pow(10, num.size()-i-1) % k + k) % k;
            ans += dp(num, i+1, bound && (x==end), df + ((x&1) ? -1 : 1), false, r);
        }
        return ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int kk) {
        k = kk;
        memset(f, -1, sizeof(f));
        int ub = dp(to_string(high), 0, true, 10, true, 0);
        memset(f, -1, sizeof(f));
        int lb = dp(to_string(low-1), 0, true, 10, true, 0);
        return ub - lb;
    }
};