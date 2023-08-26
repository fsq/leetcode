class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (find(target.begin(), target.end(), '1')!=target.end() && 
               find(s.begin(), s.end(), '1') != s.end()) || s==target;
    }
};