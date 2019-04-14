class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        for (int i=0,c=0; i<s.size(); ++i) {
            int pre = c;
            c += s[i]=='(' ? 1 : -1;
            if (!((pre==0 && c==1) || (pre==1 && c==0))) ans.push_back(s[i]);
        }
        return ans;
    }
};