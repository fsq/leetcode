class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        int c0=0, c1=0;
        for (int i=0; i<n; ++i) {
            c0 += (s[i]-'0') != (i&1);
            c1 += (s[i]-'0') != (!(i&1));
        }
        int ans = min(c0, c1);
        for (int i=1; i<n; ++i) {
            int t = c0;
            c0 = c1 - (s[i-1]!='1') + (s[i+n-1]-'0' == (n&1));
            c1 = t - (s[i-1]!='0') + (s[i+n-1]-'0' != (n&1));
            ans = min({ans, c0, c1});
        }
        return ans;
    }
};