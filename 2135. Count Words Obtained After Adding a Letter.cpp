class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        for (auto s : startWords) {
            sort(s.begin(), s.end());
            st.insert(s);
        }
        int ans = 0;
        for (auto s : targetWords) {
            sort(s.begin(), s.end());
            for (int i=0; i<s.size(); ++i)
                if ((i==0 || s[i]!=s[i-1]) && (i+1==s.size() || s[i]!=s[i+1])) {
                    auto t = s;
                    t.erase(t.begin() + i);
                    if (st.count(t)) {
                        ++ans;
                        break;
                    }
                }
        }
        return ans;
    }
};