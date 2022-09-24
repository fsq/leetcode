class Solution {
public:
    long long numberOfWays(string s) {
        long long n = s.size(), t0 = count(s.begin(), s.end(), '0'), t1 = n-t0;
        long long c0 = 0, c1 = 0, ans = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '0') {
                ans += c1 * (t1-c1);
                ++c0;
            } else {
                ans += c0 * (t0-c0);
                ++c1;
            }
        return ans;
    }
};