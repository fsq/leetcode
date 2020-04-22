class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> f(n+1);
        f[0] = 1;
        for (int i=1; i<=n; ++i) {
            long long x = 0, t = 1;
            for (int j=i; j>0 && t<=k && x<=k; --j) {
                x = x + (s[j-1]-'0') * t;
                t *= 10;
                if (s[j-1]=='0' || x>k) continue;
                f[i] = (f[i] + f[j-1]) % M;
            }
        }
        return f.back();
    }
};