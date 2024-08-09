class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        for (int l=0,r=0,c=0; r<s.size(); ++r) {
            c += s[r] == '1';
            while (l<=r && (c-(s[l]=='1')>=k)) {
                c -= s[l] == '1';
                ++l;
            }
            if (c == k) {
                if (ans.empty() || ans.size() > (r-l+1))
                    ans = s.substr(l, r-l+1);
                else if (ans.size() == (r-l+1))
                    ans = min(ans, s.substr(l, r-l+1));
            }
        }
        return ans;
    }
};