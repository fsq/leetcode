class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = count(s.begin(), s.end(), '0');
        long long now = 1;
        for (int i=s.size()-1; i>=0 && k>=now; --i) {
            if (s[i]=='1') {
                k -= now;
                ++ans;
            }
            now *= 2;
        }
        return ans;
    }
};