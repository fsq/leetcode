class Solution {
public:
    bool checkIfPangram(string s) {
        return unordered_set<char>(s.begin(), s.end()).size() == 26;
    }
};