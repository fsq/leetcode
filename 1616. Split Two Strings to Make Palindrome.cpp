class Solution {
public:
    
    bool isPan(string& s, int i, int j) {
        while (i<j) 
            if (s[i] != s[j]) return false;
            else ++i, --j;
        return true;
    }
    
    bool ok(string& a, string& b) {
        int i = 0, j = a.size()-1;
        while (i<a.size() && a[i]==b[j]) 
            ++i, --j;
        if (i >= a.size()/2) return true;
        return isPan(a, i, j) || isPan(b, i, j);
    }
    
    bool checkPalindromeFormation(string a, string b) {
        if (isPan(a, 0, a.size()-1) || isPan(b, 0, b.size()-1)) return true;
        return ok(a, b) || ok(b, a);
    }
};