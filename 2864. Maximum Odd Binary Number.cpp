class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = count(s.begin(), s.end(), '1');
        fill(s.begin(), s.end(), '0');
        for (int i=0; i<c-1; ++i) s[i] = '1';
        s.back() = '1';
        return s;
    }
};