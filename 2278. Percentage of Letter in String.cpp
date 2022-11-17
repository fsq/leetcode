class Solution {
public:
    int percentageLetter(string s, char letter) {
        int c = count(s.begin(), s.end(), letter);
        return floor(c*100.0 / s.size());
    }
};