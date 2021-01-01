class Solution {
public:
    bool halvesAreAlike(string s) {
        string v = "aeiou";
        int a=0, b=0;
        for (int i=0; i<s.size()/2; ++i) {
            if (v.find(tolower(s[i])) != string::npos)
                ++a;
        }
        for (int i=s.size()/2; i<s.size(); ++i) {
           if (v.find(tolower(s[i])) != string::npos)
                ++b;
        }
        return a == b;
    }
};