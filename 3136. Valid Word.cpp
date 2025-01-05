class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> vs = {'a','e','i','o','u'};
        if (s.size()<3) return false;
        int v=0, cs=0;
        for (auto c : s) {
            if (!isalnum(c)) return false;
            if (isdigit(c)) continue;
            if (vs.count(tolower(c))) 
                ++v; 
            else
                ++cs;
        }
        return v && cs;
    }
};