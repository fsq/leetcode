class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto i = s.find(part);
        while (i != string::npos) {
            s.erase(i, part.size());
            i = s.find(part);
        }
        return s;
    }
};