class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> ok(128);
        for (auto c : allowed) ok[c] = true;
        return count_if(words.begin(), words.end(), [&](string& s) {
            return all_of(s.begin(), s.end(), [&](char c) {
                return ok[c];
            });
        });
    }
};