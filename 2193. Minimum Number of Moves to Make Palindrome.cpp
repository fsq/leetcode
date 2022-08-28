class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        if (s.empty() || s.size()==1) return 0;
        if (s.front() == s.back()) return minMovesToMakePalindrome(s.substr(1, s.size()-2));
        auto i = s.find(s.back());
        if (i+1 == s.size()) {
            s.pop_back();
            return minMovesToMakePalindrome(s) + i / 2;
        } else {
            s.erase(s.begin() + i);
            s.pop_back();
            return minMovesToMakePalindrome(s) + i;            
        }
    }
};