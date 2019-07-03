class Solution {
public:
    
    bool f(const string& s, int& i) {
        if (s[i]=='t') {
            ++i;
            return true; 
        } else if (s[i]=='f') {
            ++i;
            return false;
        } else if (s[i]=='!') {
            i += 2;
            bool ans = f(s, i);
            ++i;
            return !ans;
        } else {
            char op = s[i++];
            bool fst = true, ans;
            while (s[i] != ')') {
                ++i;
                bool x = f(s, i);
                if (fst) {
                    ans = x;
                    fst = false;
                }
                if (op == '&') 
                    ans &= x;
                else 
                    ans |= x;
            }
            ++i;
            return ans;
        }
    }
    
    bool parseBoolExpr(string s) {
        int i = 0;
        return f(s, i);
    }
};