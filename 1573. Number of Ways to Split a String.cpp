class Solution {
public:
    int numWays(string s) {
        int tot = count(s.begin(), s.end(), '1');
        if (tot%3 != 0) return 0;
        if (tot == 0) {
            return (s.size()-2) * (s.size() - 1) / 2 % 1000000007;
        }
        int x = tot / 3, now = 0;
        long long a=0, b=0;
        for (auto c : s) {
            if (c == '1') ++now;
            if (now == x) 
                ++a;
            else if (now == x*2)
                ++b;
        }
        return a * b % 1000000007;
    }
};