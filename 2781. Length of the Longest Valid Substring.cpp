class Solution {
public:
    int longestValidSubstring(string s, vector<string>& fb) {
        int ans = 0;
        int r = s.size();
        unordered_set<string> st;
        for (auto& f : fb) st.insert(f);
        for (int i=s.size()-1; i>=0; --i) {
            for (int l=1; l<=10 && i+l<=s.size(); ++l)
                if (st.contains(s.substr(i, l))) {
                    r = min(r, i+l-1);
                    break;
                }
            ans = max(ans, r - i);
        }
        return ans;
    }
};