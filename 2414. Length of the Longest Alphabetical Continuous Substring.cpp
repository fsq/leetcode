class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, l = 1;
        for (int i=1; i<s.size(); ++i) {
            l = s[i]==s[i-1]+1 ? l + 1 : 1;
            ans = max(ans, l);
        }
        return ans;
    }
};