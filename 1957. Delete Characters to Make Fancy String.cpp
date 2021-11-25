class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for (int i=0, j=0; i<s.size(); i=j) {
            for (j=i; j<s.size() && s[j]==s[i]; ++j);
            ans += string(min(2, j-i), s[i]);
        }
        return ans;
    }
};