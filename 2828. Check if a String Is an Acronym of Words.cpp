class Solution {
public:
    bool isAcronym(vector<string>& a, string s) {
        if (a.size() != s.size()) return false;
        for (int i=0; i<a.size(); ++i)
            if (a[i][0] != s[i])
                return false;
        return true;
    }
};