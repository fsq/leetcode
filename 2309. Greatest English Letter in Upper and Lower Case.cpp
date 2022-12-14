class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> st(s.begin(), s.end());
        for (char c='z'; c>='a'; --c)
            if (st.count(c) && st.count(c+'A'-'a'))
                return string(1, c+('A'-'a'));
        return "";
    }
};