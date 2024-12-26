class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            vector<int> cnt(128);
            int j;
            for (j=i; j<s.size(); ++j) {
                if (++cnt[s[j]] > 2) break;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};