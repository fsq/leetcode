class Solution {
public:
    string modifyString(string s) {
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '?') 
                for (auto c='a'; c<='z'; ++c)
                    if ((i==0 || c!=s[i-1]) && (i+1==s.size() || c!=s[i+1])) {
                        s[i] = c;
                        break;
                    }
        return s;
    }
};