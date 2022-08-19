class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return count_if(words.begin(), words.end(), [&](string& s) {
            return pref.size() <= s.size() && equal(pref.begin(), pref.end(), s.begin());
        });
    }
};