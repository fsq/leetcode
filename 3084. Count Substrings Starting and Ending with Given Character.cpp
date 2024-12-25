class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long x = count(s.begin(), s.end(), c);
        return x * (x+1) / 2;
    }
};