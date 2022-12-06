class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if (s.size() < 8) return false;
        int m = 0;
        char pre = 0;
        string special = "!@#$%^&*()-+";
        for (auto c : s) {
            if (islower(c))
                m |= 1;
            else if (isupper(c))
                m |= 2;
            else if (isdigit(c))
                m |= 4;
            else if (special.find(c) != string::npos)
                m |= 8;
            
            if (c==pre)
                return false;
            pre = c;
        }
        return m == 15;
    }
};