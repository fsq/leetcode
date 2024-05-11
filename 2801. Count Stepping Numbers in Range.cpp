class Solution {
public:
    const int M = 1000000007;
    
    // f[i][j]: #stepping numbers of length i, first digit j. j!=0
    int f[101][10];

    int calc(string s) {
        int n = s.size();
        int ans = s=="0" ? 0 : 1;// special handle 0

        // all step numbers length 1..(n-1)
        if (n > 1) {
            for (int i=1; i<n; ++i) {
                for (int j=1; j<=9; ++j) {
                    ans = (ans + f[i][j]) % M;
                }
            }
        }

        // all step numbers length n, first digit 1..(s[0]-1)
        for (int c='1'; c<s[0]; ++c) {
            int d = c - '0';
            ans = (ans + f[n][d]) % M;
        }

        // rest
        bool ok = true;
        for (int i=1; i<n; ++i) {
            if (s[i] > s[i-1] - 1 && s[i-1]-1>='0') {
                ans = (ans + f[n-i][s[i-1]-1-'0']) % M;
            } else if (s[i] == s[i-1] - 1) {
                continue;
            }
            if (s[i] > s[i-1] + 1 && s[i-1]+1<='9') {
                ans = (ans + f[n-i][s[i-1]+1-'0']) % M;
            } else if (s[i] == s[i-1] + 1) {
                continue;
            }
            ok = false;
            break;
        }

        ans = (ans + ok) % M;
        return ans;
    }

    int countSteppingNumbers(string low, string high) {
        for (int i=0; i<=9; ++i) f[1][i] = 1;
        for (int i=2; i<=high.size(); ++i) {
            f[i][9] = f[i-1][8];
            f[i][0] = f[i-1][1];
            for (int j=1; j<=8; ++j) {
                f[i][j] = (f[i-1][j-1] + f[i-1][j+1]) % M;
            }
        }
        
        low.back() -= 1;
        for (int i=low.size()-1; i>=0; --i) 
            if (low[i] < '0') {
                low[i] += 10;
                low[i-1] -= 1;
            }
        if (low[0] == '0' && low.size()>1) {
            low.erase(0, 1);
        }
        int upper = calc(high);
        int lower = calc(low);
        return (upper - lower + M) % M;
    }
};