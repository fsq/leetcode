class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        if (a.substr(0, b.size()) != b) return "";
        return a.substr(0, gcd(a.size(), b.size()));
    }
};