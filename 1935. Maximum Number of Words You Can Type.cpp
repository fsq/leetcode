class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream sin(text);
        vector<bool> brk(128);
        for (auto c : brokenLetters) brk[c] = true;
        string s;
        int ans = 0;
        while (sin >> s) {
            ans += none_of(s.begin(), s.end(), [&](char c) {
                return brk[c] == true;
            });
        }
        return ans;
    }
};