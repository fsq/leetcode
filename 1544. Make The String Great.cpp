class Solution {
public:
    string makeGood(string s) {
        for (int i=0; i+1<s.size(); ++i)
            if (s[i+1]==s[i]-'a'+'A' || s[i]==s[i+1]-'a'+'A')
                return makeGood(s.substr(0, i) + s.substr(i+2));
        return s;
    }
};