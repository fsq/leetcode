class Solution {
public:
    string minimizeResult(string s) {
        int p = s.find('+'), ans = INT_MAX;
        string ret;
        for (int i=0; i<p; ++i)
            for (int j=p+1; j<s.size(); ++j) {
                long long x = i==0 ? 1 : stoll(s.substr(0, i));
                long long y = stoll(s.substr(i, p-i)) + stoll(s.substr(p+1, j-p));
                long long z = j+1==s.size() ? 1 : stoll(s.substr(j+1, s.size()-j-1));
                if (x*y*z < ans) {
                    ans = x*y*z;
                    ret = s.substr(0, i) + "("  + s.substr(i, j-i+1) + ")" + s.substr(j+1);
                }
            }
        return ret;
    }
};