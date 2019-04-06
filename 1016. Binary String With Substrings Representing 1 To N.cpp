class Solution {
public:
    bool queryString(string s, int n) {
        if (n > 32000) return false;
        unordered_set<int> st;
        for (int l=1; l<=16 && l<=s.size(); ++l) {
            int x = stoi(s.substr(0, l), 0, 2);
            st.insert(x);
            for (int i=1; i+l<=s.size(); ++i) {
                x &= (1<<(l-1)) - 1;
                x = x<<1 | (s[i+l]-'0');
                st.insert(x);
            }
        }
        if (st.size() < n) return false;
        for (int i=1; i<=n; ++i) 
            if (!st.count(i)) return false;
        return true;
    }
};