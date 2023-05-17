class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_set<string> st;
        for (auto s : dictionary) {
            st.insert(s);
            for (int i=0; i<s.size(); ++i) {
                auto ch = s[i];
                s[i] = '*';
                st.insert(s);
                for (int j=i+1; j<s.size(); ++j) {
                    auto c2 = s[j];
                    s[j] = '*';
                    st.insert(s);
                    s[j] = c2;
                }
                s[i] = ch;
            }   
        }
        vector<string> ans;
        for (auto s : queries) {
            bool ok = false;
            for (int i=0; i<s.size() && !ok; ++i) {
                auto ch = s[i];
                s[i] = '*';
                if (st.count(s)) {
                    ok = true;
                }
                s[i] = ch;
            }
            for (int i=0; i<s.size() && !ok; ++i) 
                for (int j=i+1; j<s.size() && !ok; ++j) {
                    auto c1 = s[i], c2 = s[j];
                    s[i] = s[j] = '*';
                    if (st.count(s)) {
                        ok = true;
                    }
                    s[i] = c1, s[j] = c2;
                }
            if (ok) ans.push_back(s);
        }
        return ans;
    }
};