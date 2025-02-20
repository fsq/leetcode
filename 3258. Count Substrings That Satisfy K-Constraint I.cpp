class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            int cnt = 0;
            for (int j=i; j<s.size(); ++j) {
                cnt += s[j] == '1';
                if (cnt<=k || (j-i+1-cnt)<=k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};