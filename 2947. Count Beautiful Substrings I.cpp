class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        string vs = "aeiou";
        for (int i=0; i<s.size(); ++i) {
            int v=0, c=0;
            for (int j=i; j<s.size(); ++j) {
                if (vs.find(s[j]) != string::npos) {
                    ++v;
                } else {
                    ++c;
                }
                if (v==c && v*c%k==0) ++ans;
            }
        }
        return ans;
    }
};