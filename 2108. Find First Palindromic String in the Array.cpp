class Solution {
public:
    
    bool ispan(string& s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (auto& s : words)
            if (ispan(s))
                return s;
        return "";
    }
};