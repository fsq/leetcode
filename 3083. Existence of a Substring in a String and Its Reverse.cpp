class Solution {
public:
    bool isSubstringPresent(string s) {
        auto t = s;
        reverse(t.begin(), t.end());
        for (int i=0; i+1<s.size(); ++i)
            if (t.find(s.substr(i, 2)) != string::npos)
                return true;
        return false;
    }
};