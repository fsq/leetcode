class Solution {
public:
    
    bool ok(string s, int i, long long x) {
        if (i==s.size()) return true;
        if (x<0) return false;
        for (int j=i; j<s.size(); ++j) {
            long long y = stoll(s.substr(i, j-i+1));
            if (y == x) {
                if (ok(s, j+1, y-1)) return true;
            } else if (y > x)
                break;
        }
        return false;
    }
    
    bool splitString(string s) {
        for (int i=0; i+1<s.size(); ++i) {
            double xd = stod(s.substr(0, i+1));
            if (xd <= LLONG_MAX) {
                long long x = xd;
                if (ok(s, i+1, x-1)) return true;
            } else 
                break;
        }
        return false;
    }
};