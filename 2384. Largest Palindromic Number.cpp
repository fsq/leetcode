class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> c(10);
        for (auto x : num) ++c[x-'0'];
        string s;
        int maxmid = -1;
        for (int i=9; i>=0; --i) {
            if (!(i==0 && s.empty()))
                s += string(c[i]/2, '0'+i);
            if ((c[i]&1) && maxmid==-1) maxmid = i;
        }
        if (maxmid==-1 && s.empty()) return "0";
        auto t = s;
        reverse(t.begin(), t.end());
        if (maxmid == -1) {
            return s + t;
        } else {
            return s + string(1, maxmid+'0') + t;
        }
    }
};