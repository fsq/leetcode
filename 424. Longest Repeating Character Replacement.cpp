class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, mx = 0, l, r;
        vector<int> cnt(128);
        for (l=0, r=0; r<s.size(); ++r) {
            mx = max(mx, ++cnt[s[r]]);
            if (r-l+1-mx > k) {
                --cnt[s[l++]];
            }
        }
        return r-l;
    }
};