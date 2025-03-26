class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> m;
        for (auto c : s) ++m[c];
        for (int i=0; i+1<s.size(); ++i)
            if (s[i] != s[i+1] && s[i]==m[s[i]]+'0' && s[i+1]==m[s[i+1]]+'0') {
                return s.substr(i, 2);
            }
        return "";
    }
};