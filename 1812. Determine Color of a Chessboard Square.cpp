class Solution {
public:
    bool squareIsWhite(string s) {
        return (s[0]-'a'+1 + s[1]-'0') & 1;
    }
};