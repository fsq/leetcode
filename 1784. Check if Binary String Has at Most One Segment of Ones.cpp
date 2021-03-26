class Solution {
public:
    bool checkOnesSegment(string s) {
        bool cont = false;
        for (int i=0, j; i<s.size(); i=j)
            if (s[i] == '0')
                j = i + 1;
            else {
                for (j=i; j<s.size() && s[j]=='1'; ++j);
                if (j > i) {
                    if (cont) return false;
                    cont = true;
                }
            }
        return true;
    }
};