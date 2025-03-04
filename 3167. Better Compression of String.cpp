class Solution {
public:
    string betterCompression(string s) {
        vector<int> cnt(26);
        for (int i=0; i<s.size(); ) {
            char c = s[i++];
            int x = 0;
            while (i<s.size() && isdigit(s[i])) {
                x = x*10 + (s[i]-'0');
                ++i;
            }
            cnt[c-'a'] += x;
        }
        string ans;
        for (int i=0; i<26; ++i)
            if (cnt[i]) {
                ans += 'a' + i;
                ans += to_string(cnt[i]);
            }
        return ans;
    }
};