class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        vector<int> f(s.size());
        f[0] = 1; f[1] = -1;
        int c = 0;
        for (int i=0; i<s.size(); ++i) {
            c += f[i];
            if (c>0 && s[i]=='0') {
                int l = i + minJump, r = min<int>(i + maxJump, s.size()-1);
                if (l <= r) {
                    ++f[l];
                    if (r+1<f.size()) --f[r+1];
                }
            }
        }
        return c > 0;
    }
};