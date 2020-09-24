class Solution {
public:
    
    int ans = 0;
    
    void dfs(string& s, unordered_set<string>& st, int i, int has) {
        if (i == s.size()) {
            ans = has;
        } else {
            string cur;
            for (int j=i; j<s.size(); ++j) {
                if (has + s.size() - j <= ans) break;
                cur += s[j];
                if (!st.count(cur)) {
                    st.insert(cur);
                    dfs(s, st, j+1, has+1);
                    st.erase(cur);
                }
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        dfs(s, st, 0, 0);
        return ans;
    }
};