class Solution {
public:
    long long ans;
    int tar;

    bool dfs(string& s, int i, int sum, long long num, bool bound) {
        if (i==s.size()) {
            ans = num;
            return true;
        }
        int lo = bound ? s[i]-'0' : 0;
        for (int j=lo; j<=9 && sum+j<=tar; ++j) {
            if (dfs(s, i+1, sum+j, num*10+j, bound&&j==lo)) return true;
        }
        return false;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);
        tar = target;
        ans = pow(10ll, s.size());
        
        dfs(s, 0, 0, 0, true);
        return ans - n;
    }
};