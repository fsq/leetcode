class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        for (int i=0; i<words.size() && t.size()<s.size(); ++i)
            t += words[i];
        return t == s;
    }
};