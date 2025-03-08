class Solution {
public:
    int pow[100001];
    int f[100001][10];
    int M;

    bool dfs(string& s, int i, int j, int rem) {
        if (i == j) {
            for (int x=9; x>=0; --x)
                if (x*pow[i] % M == rem) {
                    s[i] = '0' + x;
                    return true;
                }
            return false;
        } else if (i < j) {
            return rem==0;
        } else {
            if (f[i][rem] != -1) return f[i][rem];
            int& ans = f[i][rem];
            ans = false;

            int last = i+1==s.size() ? 1 : 0;
            for (int c=9; c>=last; --c) {
                s[i] = s[j] = '0' + c;
                int next_rem = (rem - (pow[i]*c + pow[j]*c) % M + M) % M;
                if (dfs(s, i-1, j+1, next_rem)) {
                    ans = true;
                    break;
                }
            }

            return ans;
        }
    }

    string largestPalindrome(int n, int k) {
        memset(f, -1, sizeof(f));
        M = k;
        pow[0] = 1;
        for (int i=1; i<=n; ++i)
            pow[i] = (pow[i-1] * 10) % M;
        string ans(n, ' ');
        dfs(ans, n-1, 0, 0);
        return ans;
    }
};