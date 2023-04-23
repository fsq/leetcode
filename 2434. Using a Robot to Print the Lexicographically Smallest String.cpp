class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> mn(n, -1);
        mn[n-1] = s[n-1];
        for (int i=n-2; i>=0; --i) mn[i] = min(mn[i+1], s[i]);
        string t, ans;
        for (int i=0; i<n; ++i) {
            while (!t.empty() && t.back()<=mn[i]) {
                ans.push_back(t.back());
                t.pop_back();
            }
            if (mn[i]!=s[i]) {
                t.push_back(s[i]);
            } else {
                ans.push_back(s[i]);
            }
        }
        while (!t.empty()) {
            ans.push_back(t.back());
            t.pop_back();
        }
        return ans;
    }
};
