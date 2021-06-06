class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int ans = 0;
        vector<int> cnt(128);
        string vs = "aeiou";
        for (int l=0, r=0; l<s.size(); ++l) {
            while (r<s.size() && (r==l || s[r]>=s[r-1])) {
                ++cnt[s[r++]];
            }
            int ok = true;
            for (auto c : vs)
                if (cnt[c]==0) {
                    ok = false;
                    break;
                }
            if (ok) {
                ans = max(ans, r-l);
            }
            --cnt[s[l]];
        }
        return ans;
    }
};