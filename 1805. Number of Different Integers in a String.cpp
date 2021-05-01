class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_set<string> st;
        for (int j,i=0; i<s.size(); )
            if (isalpha(s[i]))
                ++i;
            else {
                for (j=i; j<s.size() && isdigit(s[j]); ++j);
                while (i<j && s[i]=='0') ++i;
                st.insert(s.substr(i, j-i));
                i = j;
            }
        return st.size();
    }
};